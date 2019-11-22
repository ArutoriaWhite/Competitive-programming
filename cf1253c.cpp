#include<iostream>
#include<algorithm>
using namespace std;
#define maxN (200000+10)
#define int long long

int arr[maxN], sum[maxN], ans[maxN], n, m;

inline void build()
{
	sort(arr,arr+n);
	for (int i=1; i<=n; i++)
		sum[i] = sum[i-1]+arr[i-1];	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	build();

	for (int i=1; i<=m; i++)
	{
		int d=0, s=0;
		for (int k=0,j=i; j<=n; k=j,j+=m)
		{
			s += sum[j];
			ans[j]=s;
		}
	}
	for (int i=1; i<=n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
