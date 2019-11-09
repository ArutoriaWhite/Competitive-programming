#include<iostream>
#include<algorithm>
using namespace std; 

int arr[1000000+10];

int main()
{
	int n;
	while (cin>>n)
	{
		for (int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		sort(arr,arr+n);

		if (n&1)
		{
			cout << arr[n>>1] << '\n';
		}
		else
		{
			cout << arr[n>>1-1] << '\n';
		}

		int k, i;
	}
}
