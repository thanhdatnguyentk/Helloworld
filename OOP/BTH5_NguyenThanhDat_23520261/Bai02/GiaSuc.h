#ifndef GIASUC_H
#define GIASUC_H

#include <iostream>
#include <string>

using namespace std;

class GiaSuc {
protected:
    string ten;
public:
    GiaSuc();
    GiaSuc(string ten);
    virtual ~GiaSuc();
    void Nhap();
    void Xuat();
    virtual void Keu() = 0;
    virtual int Sua() = 0;
};

class Bo : public GiaSuc {
public:
    Bo();
    Bo(string ten);
    void Keu();
    int Sua();
};

class Cuu : public GiaSuc {
public:
    Cuu();
    Cuu(string ten);
    void Keu();
    int Sua();
};

class De : public GiaSuc {
public:
    De();
    De(string ten);
    void Keu();
    int Sua();
};

// GiaSuc
GiaSuc::GiaSuc() {
    ten = "";
}

GiaSuc::GiaSuc(string ten) : ten(ten) {
}

GiaSuc::~GiaSuc() {
}

void GiaSuc::Nhap() {
    cout << "Nhap ten gia suc: ";
    cin.ignore();
    getline(cin, ten);
}

void GiaSuc::Xuat() {
    cout << "Ten gia suc: " << ten << endl;
}

// Bo
Bo::Bo() : GiaSuc() {
}

Bo::Bo(string ten) : GiaSuc(ten) {
}

void Bo::Keu() {
    cout << "Um bo" << endl;
}

int Bo::Sua() {
    return rand() % 20 + 1;
}

// Cuu
Cuu::Cuu() : GiaSuc() {
}

Cuu::Cuu(string ten) : GiaSuc(ten) {
}

void Cuu::Keu() {
    cout << "Cuu cuu" << endl;
}

int Cuu::Sua() {
    return rand() % 5 + 1;
}

// De
De::De() : GiaSuc() {
}

De::De(string ten) : GiaSuc(ten) {
}

void De::Keu() {
    cout << "De de" << endl;
}

int De::Sua() {
    return rand() % 10 + 1;
}

#endif
