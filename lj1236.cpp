#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define rep(i,j,k) for (int i=j; i<k; i++)
using namespace std;
typedef pair<int,int> Pii;

int n[4], flag;
string ch = "+-*/";

inline int v (int x, int y, int o)
{
    if (x<y) swap(x,y);
    if (o == 0) return x+y;
    if (o == 1) return x-y;
    if (o == 2) return x*y;
    if (y==0 || x%y!=0)
    {
        flag = 0;
        return 1;
    }
    return x/y;
}
inline void print (int x, int y, int o)
{
    if (x < y) swap(x,y);
    cout << x << ch[o] << y << '=' << v(x,y,o) << '\n';
}

int main()
{
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    rep(a,0,4)
    {
        rep(b,0,4)
        {
            if (b==a) continue;
            rep(c,0,4)
            {
                if (c==b || c==a) continue;
                rep(d,0,4)
                {
                    if (d==a || d==b || d==c) continue;
                    rep(i,0,4)
                    {
                        rep(j,0,4)
                        {
                            rep(k,0,4)
                            {
                                flag=1;
                                if ( v( v(n[a],n[b],i), v(n[c],n[d],j), k) == 24 && flag)
                                {
                                    print(n[a],n[b],i);
                                    print(n[c],n[d],j);
                                    print(v(n[a],n[b],i),v(n[c],n[d],j),k);
                                    return 0;                                        
                                }
                                flag=1;
                                if ( v(v(v(n[a],n[b],i),n[c],j),n[d],k) == 24 && flag)
                                {
                                    print(n[a],n[b],i);
                                    print(v(n[a],n[b],i), n[c], j);
                                    print(v( v(n[a],n[b],i), n[c], j), n[d], k);
                                    return 0;
                                }
                            }
                        }
                    }    
                }
            }
        }
    }
    cout << "No answer!\n";
}
