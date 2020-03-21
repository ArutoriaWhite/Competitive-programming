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
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 100;

int arr[N], n;

int main()
{
	akiyama;
	while (cin >> n)
	{
		for (int i=0; i<n; i++)
			arr[i] = n-i;
		do
		{
			for (int i=0; i<n; i++)
				cout << arr[i];
			cout << '\n';
		}while (prev_permutation(arr,arr+n));

	}
}


