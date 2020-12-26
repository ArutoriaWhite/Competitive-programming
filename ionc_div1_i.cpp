#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define NewYearBurst ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

vector<int> adj[N];
int n, m;


signed main()
{
    cin >> n >> m;
    for (int i=0, a, b; i<m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
}