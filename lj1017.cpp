#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e7;

int q,r, g, k, res[N];

int main()
{
    yukari;
    cin >> q >> g;
    cout << q << '=';
    while (q!=0)
    {
        r = q%g, q = q/g;
        if (r<0 && g>0)
            r += g, q--;
        else if (r<0 && g<0)
            r -= g, q++;
        res[k++] = r;
    }
    for (int i=k-1; i>=0; i--)
    {
        if (res[i]>9)
            cout << (char)(res[i]-10+'A');
        else
            cout << res[i];
    }
    cout << "(base" << g << ")\n";
}