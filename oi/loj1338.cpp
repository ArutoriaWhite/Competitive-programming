#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb emplace_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f;

int arr[100], n;

int main()
{
	cin >> n;
	for (int i=0; i<n; i++)
		arr[i] = i+1;
	for (int i=0; i<120; i++)
	{
		for (int i=0; i<n; i++)
			cout << arr[i] << ' ';
		int cnt = 0;
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				if (arr[i]>arr[j]) cnt++;
		de(cnt), dend;
		next_permutation(arr,arr+n);
	}
}
