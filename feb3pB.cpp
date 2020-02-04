#pragma GCC optimize("O3")
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int N = 2e5+10;

unordered_map<int,int> cnt;
int sub[N], aud[N], id[N];
int n, m;

inline bool cmp (int a, int b)
{
	int x, y;
	x = cnt[aud[a]], y=cnt[aud[b]];
	if (x!=y)
		return x>y;
	return cnt[sub[a]]>cnt[sub[b]];
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i=0,x; i<n; i++)
		cin >> x, cnt[x]++;
	cin >> m;
	for (int i=0; i<m; i++)
		cin >> aud[i], id[i] = i;
	for (int i=0; i<m; i++)
		cin >> sub[i];
	sort(id,id+m,cmp);
	cout << id[0]+1 << '\n';
}
