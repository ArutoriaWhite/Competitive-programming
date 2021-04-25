#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e3+10;

struct vec
{
	int x[6];
	vec operator - (vec b)
	{

	}
} a[N];

int dot (vec a, vec b)
{
	int res=0;
	for (int i=0; i<5; i++)
	{
		res += a.x[i]*b.x[i];
	}
	return res;
}

signed main()
{
	cin >> n;
	rep(i,1,n)
		rep(j,1,5);
			cin >> a[i].x[j];
	// enum vecs, turn into angle 
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			if (i==j) continue;
			vec x = a[i]-a[j], y =  
			double c = 
		}
	}
}

