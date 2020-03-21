//pc
#include <iostream>
#define int long long
using namespace std;

int n, a, b, x[110], y[110], res;

inline bool tri (int b1, int b2, int s1, int s2)
{
	return (s1<=b1 && s2<=b2) || (s2<=b1 && s1<=b2);
}
inline bool can (int i, int j)
{
	return tri(a-x[i],b,x[j],y[j]) || 
		   tri(b-y[i],a,x[j],y[j]) ||
		   tri(a-y[i],b,x[j],y[j]) ||
		   tri(b-x[i],a,x[j],y[j]);
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> a >> b;
	for (int i=0; i<n; i++) cin >> x[i] >> y[i];
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (can(i,j)) res = max(res,x[i]*y[i]+x[j]*y[j]);
	cout << res << '\n';
}
