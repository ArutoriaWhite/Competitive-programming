#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int n, k;
struct B {int t, a, b;} bks[N];
set<B> canu;

signed main()
{
	cin >> n >> k;
	rep(i,1,n) cin >> bks[i].t >> bks[i].a >> bks[i].b;
	sort(bks+1,bks+1+n,cmpa);
	sort(bks+1,bks+1+n,cmpb);
	
}
