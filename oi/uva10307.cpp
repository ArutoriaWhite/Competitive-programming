#include<iostream>
#include<iomanip>
using namespace std;
#define maxN 1010

int arr[maxN];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		double s=0;
		cin >> n;
		for( int i=0; i<n; i++)
		{
			cin >> arr[i];
			s+=arr[i];
		}

		s/=n;
		int cnt=0;
		for (int i=0; i<n; i++)
		{
			if (arr[i]>s) cnt++;
		}

		cout << fixed << setprecision(3) << ((double)cnt/n)*100  << '%' << '\n';
	}
}
