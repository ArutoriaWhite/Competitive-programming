#include <iostream>
#define DE cout << " ::"
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int sum=0;
		bool flag=0;
		for (int i=0,x,prev; i<n; i++,prev=x)
		{
			cin >> x;
			sum += x;
			if (i>0 && (abs(prev-x)&1)) flag=1;
		}
		if (sum&1 || flag) cout << "YES\n";
		else cout << "NO\n";
	}
}
