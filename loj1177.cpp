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
const int INF=0x7f7f7f7f, N = 1e5+10;

int arr[N], n, tmp[N];

inline void merge (int l, int r)
{
	int m = (l+r)>>1;
	for (int i=l,j=m,k=l; k<r; k++)
	{
		if (i<m && (j>=r || arr[i]<arr[j])) tmp[k] = arr[i++];
		else tmp[k] = arr[j++];
	}
	for (int i=l; i<r; i++) arr[i] = tmp[i];
}
inline void merge_sort (int l, int r)
{
	if (r-l<=1) return;
	int m = (l+r)>>1;
	merge_sort(l,m);
	merge_sort(m,r);
	merge(l,r);
}

inline void test_merge()
{
	int x;
	while (cin >> x)
	{
		for (int i=0; i<x; i++)
			cin >> arr[i];
		merge(0,x);
		for (int i=0; i<x; i++)
			cout << arr[i] << ' ';
	}
}
int main()
{
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	merge_sort(0,n);
	for (int i=0; i<n; i++)
		cout << arr[i] << "\n "[i+1<n];
}
