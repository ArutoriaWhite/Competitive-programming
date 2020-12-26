#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int M=1e5+10;

vector<int> sh, ni;
int n, m;

signed main()
{
	cin >> n >> m;
	for (int i=0,a,b; i<m; i++)
	{
		cin >> a >> b;
		if (b==0) sh.push_back(a);
		else ni.push_back(a);
	}
	int st=
}

