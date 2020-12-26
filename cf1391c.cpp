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
const int M = 1e9+7;

int fac (int x)
{
	int res=1;
	rep(i,1,x) res = (res*i)%M;
	return res;
}
int qpow (int i, int j)
{
	int res=1;
	for (; j; j>>=1,i=i*i%M)
		if (j&1) res=(res*i)%M;
	return res;
}

signed main()
{
	int n;
	cin >> n;
	cout << (fac(n)-qpow(2,n-1)+M)%M << '\n';
}
