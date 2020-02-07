#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+10;

int a[N], b[N], id[N], n, k, j, res;

inline bool cmp (int x, int y)
{
	return a[x]-b[x] < a[y]-b[y];
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	for (int i=0; i<n; i++) id[i] = i;
	sort(id,id+n,cmp);
	for (j=k; a[id[j]]-b[id[j]]<0 && j<n; j++);
	for (int i=0; i<j; i++) res += a[id[i]];
	for (int i=j; i<n; i++) res += b[id[i]];
	cout << res << '\n';
}
//pa
