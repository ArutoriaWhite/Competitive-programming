#include <algorithm>
#include <iostream>
#define DE cout << " ::"
using namespace std;
const int N = 110;

int id[N], vol[N], add[N], ans[N];
int n, w, total;

inline bool cmp (int a, int b) { return vol[a]<vol[b]; }
inline void rise()
{
	int i=n-1;
	while (total<w && i>=0)
	{
		total++;
		add[id[i]]++;
		if (add[id[i]]>=vol[id[i]]) i--;
	}
}
inline void print()
{
	for (int i=0; i<n; i++)
		cout << add[i] << ' ';
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
		if (i==0) add[id[i]] = ((vol[id[i]]+1)>>1);
		else add[id[i]] = (max(add[id[i-1]],(vol[id[i]]+1)>>1));
		total += add[id[i]];	
	}
	if (total>w) cout << -1 << '\n';
	else rise(), print();
}
