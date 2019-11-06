#include<iostream>
#include<algorithm>
using namespace std;
#define maxN 1000010

int n, arr[maxN];
int t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
		
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		
		if (x>arr[n-1]) cout << arr[n-1] << " no\n";
		else if (x<arr[0]) cout << "no " << arr[0] << '\n';
		else
		{
			int i=0, s=n-1;
			while (s>0)
			{
				if (i+s>=n || arr[i+s]>=x)
				{
					s>>=1;
				}	
				else
				{
					i+=s;
				}
			}
			if (arr[i+1] == x) cout << x << '\n';
			else cout << arr[i] << ' ' << arr[i+1] << '\n';		
		}
	}
	
}
