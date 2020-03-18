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
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 5e7+10;

int arr[N], n, T;


inline bool check ()
{
	for (int i=0; i+2<n; i++)
		if (arr[i]+arr[i+1] > arr[i+2])
			return 1;
	return 0;
}

int main()
{
	akiyama;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> arr[i];
		sort(arr,arr+n);
		if (check()) cout << "YES\n";
		else cout << "NO\n";
	}
}

