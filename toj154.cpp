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
const int N = 1e5+10;

int arr[N], id[N], n, t;

int cmp (int i, int j){ return (arr[i]==arr[j]? i<j : arr[i] > arr[j]); }
 
signed main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		rep(i,1,n)
			cin >> arr[i], id[i] = i;
		sort(id+1,id+1+n,cmp);
		rep(i,1,n) cout << id[i] << " \n"[i+1>n];
		int sum=0;
		rep(i,1,n) sum += arr[id[i]]*i;
		cout << sum << '\n';
	}
}
