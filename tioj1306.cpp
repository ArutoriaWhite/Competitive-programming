#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string t, p;
int f[10010], T, Q;

inline void build()
{
    f[0] = -1, f[1] = 0;
    for (int i=1,j=0; i<p.size(); i++,j++,f[i]=j)
        while (j!=-1 && p[i] != p[j]) j = f[j];
}
inline int kmp()
{
    int res = 0;
    for (int i=0,j=0; i<t.size(); i++,j++)
    {
        while (j!=-1 && t[i] != p[j]) j = f[j];
        res += (j==p.size()-1);
    }
    return res;
}

int main()
{
    Eriri
    cin >> T;
    while (T--)
    {
        cin >> t >> Q;
        while (Q--)
        {
            cin >> p;
            build();
            cout << kmp() << '\n';
        }
    }
}