#include <bits/stdc++.h>
using namespace std;
const int N = 110;

int id[N], vol[N], fill[N], ans[N];
int n, w;

inline bool cmp (int a, int b) { return vol[a]<vol[b]; }
inline void rise()
{
	
}
inline void print()
{
	for (int i=0; i<n; i++)
		cout << fill[i] << ' ';
	cout << '\n';
}
int main()
{
	cin >> n >> w;
	for (int i=0; i<n; i++)
		cin >> vol[i], id[i] = i;
	sort(id,id+n,cmp);

	for (int i=0; i<n; i++)
	{
		fill[id[i]] = (i==0)? vol[id[i]]>>1 : max(fill[id[i-1]],vol[id[i]]>>1);
		total += id[i];	
	}
	print();
	if (total>w) cout << -1 << '\n';
	rise();
	print();


}
