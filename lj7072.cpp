#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

priority_queue<int, vector<int>, greater<int>> lpq; // left, get max
priority_queue<int, vector<int>, less<int>> rpq;
int n, w, a[N];

signed main()
{
    SakuraMyWife
    cin >> n >> w;
    rep(i,1,n)
    {
        int x;
        cin >> x;
        if (lpq.empty() && rpq.empty()) lpq.push(x);
        else if (x >= lpq.top()) lpq.push(x);
        else rpq.push(x);

        int k = max(1LL, i*w/100);
        while (!lpq.empty() && lpq.size()>k)
            rpq.push(lpq.top()), lpq.pop();
        while (!rpq.empty() && lpq.size()<k)
            lpq.push(rpq.top()), rpq.pop();
        //de(k), de(lpq.size()), de(rpq.size());
        cout << lpq.top() << ' ';
    }
    cout << '\n';
}