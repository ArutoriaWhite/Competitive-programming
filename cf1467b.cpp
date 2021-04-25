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
const int N = 3e5+10;

int t, n, a[N];
int best, sum;

int owo (int i) // i = 1~n; i: center
{
    if (i<=1 || i>=n) return 0;
    return (a[i-1]<a[i]&&a[i]>a[i+1]) || (a[i-1]>a[i]&&a[i]<a[i+1]);
}
int calc (int i) // i = 1~n
{
    return owo(i-1)+owo(i)+owo(i+1);
}
void change (int i, int x)
{
    int tmp = a[i];
    int bef = calc(i);
    a[i] = x;
    int aft = calc(i);
    a[i] = tmp;
    best = min(best, sum-bef+aft);
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i];

        sum = 0;
        rep(i,1,n) sum += calc(i); // i-1 is && i+1 is && i is
        sum /= 3;
        best = sum;

        a[0] = a[1], a[n+1] = a[n];
        rep(i,1,n)
        {
            change(i,a[i-1]);
            change(i,a[i+1]);
        }
        cout << best << '\n';
    }
}