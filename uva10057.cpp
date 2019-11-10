#include<iostream>
#include<algorithm>
#define DE cout << " ::"
using namespace std; 

int arr[1000000+10];

inline int extl( int n)
{
	int i, k;
	for (i=n,k=1; arr[i-1]==arr[i]; i--,k++);
	return k;
}
inline int extr( int n)
{
	int i, k;
	for (i=n,k=1; arr[i+1]==arr[i]; i++,k++);
	return k;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin>>n)
	{
		for (int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		sort(arr,arr+n);

		int m = n>>1;
		if (n&1) cout << arr[m] << ' ';
		else     cout << arr[m-1] << ' ';

		if (n&1) cout << extl(m)+extr(m)-1 << ' ';
		else	 cout << extl(m-1) + extr(m) << ' ';

		if (n&1) cout << "1\n";
		else cout << (arr[m]-arr[m-1]+1) << '\n';
	}
}





