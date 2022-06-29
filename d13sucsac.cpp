#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll h[10][10];

void hoanvi()
{
    h[0][0] = 0;
    h[0][1] = 1;
    h[0][2] = 2;
    h[1][0] = 0;
    h[1][1] = 2;
    h[1][2] = 1;
    h[2][0] = 1;
    h[2][1] = 0;
    h[2][2] = 2;
    h[3][0] = 1;
    h[3][1] = 2;
    h[3][2] = 0;
    h[4][0] = 2;
    h[4][1] = 0;
    h[4][2] = 1;
    h[5][0] = 2;
    h[5][1] = 1;
    h[5][2] = 0;
}

ll ss[10][10];
ll tt[24][20];
ll res = -1e9;
int main()
{
    hoanvi();
    for (int i = 0; i < 4; i++)
        cin >> ss[i][3] >> ss[i][2] >> ss[i][0] >> ss[i][5] >> ss[i][1] >> ss[i][4];
    // tren duoi phai trai truoc sau

    ll dem = 0;
    for (int p = 0; p < 6; p++)
    {
        for (int d = 0; d < 6; d++)
        {
            if (d != p && d + p != 5)
            {
                tt[dem][0] = p;
                tt[dem][1] = d;
                dem++;
            }
        }
    }
    // hoan vi
    for (int j = 0; j < 6; j++)
    {
        for (int s0 = 0; s0 < 24; s0++) // ss1
        {

            for (int s1 = 0; s1 < 24; s1++) // ss1
            {

                for (int s2 = 0; s2 < 24; s2++) // ss1
                {

                    for (int s3 = 0; s3 < 24; s3++) // ss1
                    {
                        bool ktr = true;
                        // ss trong hv

                        // ktra ss1 mat phai //ss tt z trong hv tt j
                        if (ss[0][tt[s0][0]] != ss[h[j][0] + 1][5 - tt[s1][0]])
                        {
                            ktr = false;
                        }
                        if (ss[0][tt[s0][1]] != ss[h[j][1] + 1][5 - tt[s1][1]])
                        {
                            ktr = false;
                        }
                        if (ss[h[j][0] + 1][tt[s1][1]] != ss[h[j][2] + 1][5 - tt[s3][1]])
                        {
                            ktr = false;
                        }
                        if (ss[h[j][1] + 1][tt[s2][0]] != ss[h[j][2] + 1][5 - tt[s3][0]])
                        {
                            ktr = false;
                        }

                        if (ktr == true)
                        {
                            // 0 phai 1 duoi
                            ll t = 0;
                            for (int i = 0; i < 6; i++)
                            {
                                t += ss[0][i];
                            }
                            for (int i = 0; i < 6; i++)
                            {
                                t += ss[h[j][0] + 1][i];
                            }
                            for (int i = 0; i < 6; i++)
                            {
                                t += ss[h[j][1] + 1][i];
                            }
                            for (int i = 0; i < 6; i++)
                            {
                                t += ss[h[j][2] + 1][i];
                            }

                            t -= ss[0][tt[s0][1]] + ss[0][tt[s0][0]];
                            t -= ss[h[j][0] + 1][tt[s1][1]] + ss[h[j][0] + 1][5 - tt[s1][0]];
                            t -= ss[h[j][1] + 1][5 - tt[s2][1]] + ss[h[j][1] + 1][tt[s2][0]];
                            t -= ss[h[j][2] + 1][5 - tt[s3][1]] + ss[h[j][2] + 1][5 - tt[s1][0]];

                            res = max(t, res);
                        }
                    }
                }
            }
        }
    }
    if (res == -1e9)
    {
        cout << -1;
        return 0;
    }
    else
        cout << res;
}