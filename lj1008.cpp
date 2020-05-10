#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define rep(i) for (int i=1; i<=9; i++)
#define IF(i) if (!vis[i] && (vis[i]|=(!vis[i])))
using namespace std;
typedef pair<int,int> Pii;

int a, b, c;
int vis[10];

int main ()
{
    Eriri;
    for (int i=1; i<=9; i++)
    {
        vis[i] = 1;
        for (int j=i+1; j<=9; j++)
        {
            vis[j] = 1;
            for (int k=j+1; k<=9; k++)
            {
                vis[k] = 1;
                rep(x)
                {
                    IF(x)
                    {
                        rep(y)
                        {
                            IF(y)
                            {
                                rep(z)
                                {
                                    IF(z)
                                    {
                                        rep(p)
                                        {
                                            IF(p)
                                            {
                                                rep(q)
                                                {
                                                    IF(q)
                                                    {
                                                        rep(r)
                                                        {
                                                            IF(r)
                                                            {
                                                                a = i*100 + x*10 + p;
                                                                b = j*100 + y*10 + q;
                                                                c = k*100 + z*10 + r;
                                                                if (a*6==b*3 && b*3==c*2)
                                                                    cout << a << ' ' << b << ' ' << c << '\n';
                                                                vis[r] = 0;
                                                            }
                                                            a -= p, b -= q, c -= r;
                                                        }
                                                        vis[q] = 0;
                                                    }
                                                }
                                                vis[p] = 0;
                                            }
                                        }
                                        vis[z] = 0;
                                    }
                                }
                                vis[y] = 0;
                            }
                        }
                        vis[x] = 0;
                    }
                }
                vis[k] = 0;
            }
            vis[j] = 0;
        }
        vis[i] = 0;
    }
}