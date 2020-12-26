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
const int N = 1e6+10;

int arr[N], n;

signed main()
{
	XinAi
	cin >> n;
	rep(i,1,n) cin >> arr[i];
	sort(arr+1,arr+1+n);
	rep(i,1,n) cout << arr[i] << ' ';
	cout << '\n';
}
