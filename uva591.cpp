#include <iostream>
using namespace std;

int n, sum, arr[55], t, res;

int main()
{
	while (cin >> n&&n)
	{
		res=0, sum=0;
		for (int i=0; i<n; i++)
			cin >> arr[i], sum+=arr[i];
		for (int i=0; i<n; i++)
			res += max(0,arr[i]-sum/n);
		cout << "Set #" << ++t << "\n";
		cout << "The minimum number of moves is " << res << ".\n\n";
	}
}
