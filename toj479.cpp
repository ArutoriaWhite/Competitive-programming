#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 6e3+10, Q = 1e6+10;

int n, q;
int a[N], b[N], ql[Q], qr[Q], ans[Q], id[Q];
int prev_mid, prev_ans, pl, pr;

inline bool cmp (int i, int j)
{
    if (ql[i] + qr[i] == ql[j] + qr[j])
        return qr[i] < qr[j];
    return ql[i] + qr[i] < ql[j] + qr[j];
}

signed main()
{
    Eriri
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
    for (int i=1; i<=q; i++)
        cin >> ql[i] >> qr[i];
    for (int i=1; i<=q; i++)
        id[i] = i;
    sort(id+1,id+1+q,cmp);
    for (int i=1; i<=q; i++)
    {
        if (ql[id[i]] + qr[id[i]] != prev_mid)
        {
            prev_mid = ql[id[i]] + qr[id[i]];
            prev_ans = 0;
            for (int j=ql[id[i]],k=qr[id[i]]; j<=qr[id[i]]; j++,k--)
                prev_ans += abs(a[j] - b[k]);
        }
        else
        {
            for (int j=ql[id[i]],k=qr[id[i]]; j<pl; j++,k--)
                prev_ans += abs(a[j] - b[k]);
            for (int j=qr[id[i]],k=ql[id[i]]; j>pr; j--,k++)
                prev_ans += abs(a[j] - b[k]);            
        }
        ans[id[i]] = prev_ans;
        pl = ql[id[i]], pr = qr[id[i]];
    }
    for (int i=1; i<=q; i++)
        cout << ans[i] << '\n';
}
/*
5 4
1 4 3 8 7
2 6 5 1 9
1 3
1 5
2 5
3 3
*/