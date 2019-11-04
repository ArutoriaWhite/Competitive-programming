#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n, k, mx=-1;
    cin >> n >> k;

    for (int i=0; i<n; i++)
    {
		int x;
		cin >> x;
		if (x>mx)
		{
			mx = x;
		}
    }
	
	cout << fixed << setprecision(4) << mx << '\n';

	if (mx>k)
	{
		cout << "I'm the bone of my sword\n";
	}
	else
	{
		cout << "You have been slain\n";
	}
}
