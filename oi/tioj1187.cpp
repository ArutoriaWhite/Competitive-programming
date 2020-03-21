#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 1e6;

int arr[N], mx, mn, n, u;
double res;

int main()
{
	while (cin >>  n && n)
	{
		res = 0;
		for (int i=0; i<n; i++)
			cin >> arr[i];
		sort(arr,arr+n);
		for (int i=1; i<n-1; i++)
			res += arr[i];
		cout << fixed << setprecision(2) << (double)res/(n-2) << '\n';
	}
}


