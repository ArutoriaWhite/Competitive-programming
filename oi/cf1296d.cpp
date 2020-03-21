#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+10;

int need[N], n, a, b, k, res;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> a >> b >> k;
	for (int i=0,x; i<n; i++)
		cin >> x, x=(x-1)%(a+b), need[i] = (x<a)? (0) : (x/a);
	sort(need,need+n);
	for (int i=0; i<n&&k>=need[i]; k-=need[i],res++,i++);
	cout << res << '\n';
}
