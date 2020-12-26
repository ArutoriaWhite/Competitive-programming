#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 10;

int a[N];

signed main()
{
    int q;
    cin >> q;
    while (q--)
    {
        cin >> a[1] >> a[2] >> a[3] >> a[4];
        sort(a+1,a+1+4);
        int cnt=0;
        do
        {
            if (a[1]+a[3] == a[2]+a[4])
                cnt++;
        }while (next_permutation(a+1,a+1+4));
        cout << cnt << '\n';
    }
}