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
    int l = y, r = 2e9, mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (find(x, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    long long t = r;
    l = y * -1, r = 2e9, mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (find(x, mid * -1))
            l = mid + 1;
        else
            r = mid - 1;
    }
    long long b = r * -1;
    l = x, r = 2e9, mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (find(mid, y))
            l = mid + 1;
        else
            r = mid - 1;
    }
    long long phai = r;
    l = x * -1, r = 2e9, mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (find(mid * -1, x))
            l = mid + 1;
        else
            r = mid - 1;
    }
    long long trai = r * -1;
    cout << "answer " << trai << " " << b << " " << phai << " " << t << endl;
}