#include<iostream>
#include<algorithm>
using namespace std;
#define maxN (1000000+10)

int n, arr[maxN];

int bs_upl( int x)
{
	int l=0, r=n-1, m;
	while (l<r)
	{
		m = (l+r+1)>>1;
		if (arr[m]>x)
		{
			r = m-1;
		}
		else
		{
			l = m;
		}
	}
	return arr[l];
}
int bs_lwr( int x)
{
	int l=0, r=n-1, m;
	while (l<r)
	{
		m = (l+r)>>1;
		if (arr[m]<x)
		{
			l = m+1;
		}
		else
		{
			r = m;
		}
	}
	return arr[l];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	
	int q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		if (x>arr[n-1])
		{
			cout << arr[n-1] << " no\n";
		}
		else if (x<arr[0])
		{
			cout << "no " << arr[0] << "\n";
		}
		else
		{
			int upl = bs_upl(x);
			int lwr = bs_lwr(x);
			if (upl==lwr)
			{
				cout << upl << '\n';
			}
			else
			{
				cout << upl << ' ' << lwr << '\n';
			}
		}
	}
	return 0;
}
