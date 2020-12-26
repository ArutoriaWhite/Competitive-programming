#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int cnt[N], a[N], res, n;

signed main()
{
    XinAi
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cnt[a[i]]++;
    for (int i=1; i<=n; i++) res += cnt[i]*(cnt[i]-1)/2;
    for (int i=1; i<=n; i++)
    {
        int tmp = res;
        tmp -= (cnt[a[i]]*(cnt[a[i]]-1))/2;
        cnt[a[i]]--;
        tmp += (cnt[a[i]]*(cnt[a[i]]-1))/2;
        cnt[a[i]]++;
        cout << tmp << '\n';
    }
}