#include "Bai02.h"

void PhanSo::Nhap()
{
    cout << " Moi ban nhap mau so va tu so: " << endl;
    cin >> tu >> mau;
}

void PhanSo::Xuat()
{
    cout << " Phan so: ";
    cout << tu << "/" << mau << endl;
}

int PhanSo::get_mau()
{
    return this->mau;
}

int PhanSo::get_tu()
{
    return this->tu;
}

void PhanSo::set_mau(int a)
{
    this->mau = a;
}

void PhanSo::set_tu(int a)
{
    this->tu = a;
}

void PhanSo::GiaTri()
{
    double giatri = mau / tu;
    cout << giatri;
}
PhanSo PhanSo::operator+( PhanSo a)
{
    PhanSo result;
    result.set_mau(mau * a.get_mau());
    result.set_tu(tu * a.get_mau() + a.get_tu() * mau);
    return result;
}
PhanSo PhanSo::operator-( PhanSo a)
{
    PhanSo result;
    result.set_mau(mau * a.get_mau());
    result.set_tu(tu * a.get_mau() - a.get_tu() * mau);
    return result;
}
PhanSo PhanSo::operator*( PhanSo a)
{
    PhanSo result;
    result.set_mau(mau * a.get_mau());
    result.set_tu(tu * a.get_tu());
    return result;
}
PhanSo PhanSo::operator/( PhanSo a)
{
    PhanSo result;
    result.set_mau(mau * a.get_tu());
    result.set_tu(tu * a.get_mau());
    return result;
}

PhanSo::PhanSo( PhanSo &temp)
{
    mau = temp.get_mau();
    tu = temp.get_tu();
}



PhanSo::PhanSo()
{
    this->set_mau(1);
    this->set_tu(0);
}

PhanSo::~PhanSo()
{
    cout <<" Da huy phan so " << get_tu()<< "/" << get_mau()<<endl;  
}

PhanSo PhanSo::better(PhanSo &temp){
    if (this->get_tu()* temp.get_mau() > temp.get_tu()*this->get_mau())
        return *this;
    return temp;
} 

PhanSo PhanSo::worse(PhanSo &temp){
    if (this->get_tu()* temp.get_mau() < temp.get_tu()*this->get_mau())
        return *this;
    return temp;
} 

bool PhanSo::operator== (PhanSo a){
    if (this->get_tu() * a.get_mau() == this->get_mau() * a.get_tu())
        return true;
    return false;
}
