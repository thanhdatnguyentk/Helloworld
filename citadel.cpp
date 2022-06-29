#include <bits/stdc++.h>

using namespace std;

long long x, y;

bool find(long long x, long long y)
{
    int i;
    cout << "find " << x << " " << y << endl;
    cin >> i;
    if (i == 1)
        return true;
    return false;
}

int main()
{
    cin >> x >> y;
    int l = y, r = 2e9, mid, t;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (find(x, mid))
            l = mid + 1;
        else
            r = mid - 1, t = mid;
    }
    l = y * -1, r = 2e9, mid;
    long long b;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (find(x, mid * -1))
            l = mid + 1;
        else
            r = mid - 1, b = mid;
    }
    b *= -1;
    long long phai = r;
    l = x, r = 2e9, mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (find(mid, y))
            l = mid + 1;
        else
            r = mid - 1, phai = mid;
    }
    long long trai = r * -1;
    l = x * -1, r = 2e9, mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (find(mid * -1, x))
            l = mid + 1;
        else
            r = mid - 1, trai = mid;
    }
    trai *= -1;
    cout << "answer " << trai - 1<< " " << b - 1<< " " << phai - 1 << " " << t - 1<< endl;
}