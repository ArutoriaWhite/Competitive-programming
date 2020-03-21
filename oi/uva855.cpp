#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e4+10;

int t, s, a, f, x[N], y[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> s >> a >> f;
		for (int i=0; i<f; i++)
			cin >> x[i] >> y[i];
		sort(x,x+f), sort(y,y+f);
		cout << "(Street: " << x[(f-1)>>1] << ", Avenue: " << y[(f-1)>>1] <<")\n";
	}
}
