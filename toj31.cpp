#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 4e6+10;

int l[N], r[N], sz[N], pr[N], v[N];
int lz[N], rev[N], sum[N], lsum[N], rsum[N], msum[N];
int n, m, rt;

inline int node (int x)
{

}
inline void pull (int u)
{

}
inline void push (int u)
{

}
inline void split (int u, int k, int &a, int &b)
{

}
inline int merge (int a, int b)
{

}
inline void ins (int k, int x)
{

}
inline void del (int p)
{

}
inline void make_same (int p, int k, int l)
inline void reverse (int p, int k)
{

}
inline int get_sum (int p, int k)
{

}
inline int mxsum (int p, int k)
{

}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a, ins(sz[rt],a);
    string s;
    int p, k;
    for (int i=1; i<=m; i++)
    {
        cin >> opr >> p >> k;
        if (opr == "MAX-SUM")
        {
            cout << mxsum() << '\n';
        }
        else if (opr[0] == 'I')
            for (int j=0; j<k; j++)
                cin >> a, ins(p+j,a);
        else if (opr[0] == 'D')
            for (int j=0; j<k; j++)
                del(p-1);
        else if (opr[0] == 'M')
            cin >> l, make_same(p,k,l);
        else if ()

    }
}