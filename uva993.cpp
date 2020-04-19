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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0;

int n, T, res[100], r;

int find (int x)
{
    for (int i=9; i>=2; i--)
    {
        if (x%i==0) 
            return i;
    }

    return -1;
}

int main()
{
    yukari;
    cin >> T;
    while (T--)
    {
        r=0;
        cin >> n;
        bool flag=1;
        if (n==1)
        {
            cout << 1 << '\n';
            continue;
        }
        while (n>1) 
        {
            int x = find(n);
            if (x==-1)
            {
                flag=0; 
                break;
            }
            res[r++] = x;
            n/=x;
        }

        if (flag)
        {
            for (int i=r-1; i>=0; i--)
                cout << res[i];
            cout << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
}