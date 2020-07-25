#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 5010;

struct e {int p, w, id;} arr[N];
int pre[N], suf[N], n, ans;
inline bool cmp (e x, e y){
    return x.p < y.p;
}

signed main()
{
    Eriri
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> arr[i].p >> arr[i].w;
        arr[i].id = i;
    }
    sort(arr+1,arr+n+1,cmp);
    for (int i=1; i<=n; i++)
    {
        pre[i] = arr[i].w;
        for (int j=1; j<i; j++)
            if (arr[j].id > arr[i].id)
                pre[i] = max(pre[i], pre[j]+arr[i].w);
        ans = max(ans, pre[i]);
    }
    for (int i=n; i>0; i--)
    {
        suf[i] = arr[i].w;
        for (int j=n; j>i; j--)
            if (arr[j].id > arr[i].id)
                suf[i] = max(suf[i], suf[j]+arr[i].w);
        ans = max(ans, suf[i]);
    }
    for (int i=2; i<n; i++)
        ans = max(ans, pre[i]+suf[i]-arr[i].w);
    cout << ans << '\n';
}
/*
4
1 3
4 1
3 2
2 4
*/