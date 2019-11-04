#include<iostream>
#include<string.h>
using namespace std;
#define id(x) ('x'-'A')

int arr[3][30], t[3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		memset(arr,0,sizeof(arr));

		for (int i=0; i<3; i++)
		{
			string a, b, k;
			cin >> a >> b >> k;
			cout << a << ' ' << b << ' ' << k <<  '\n';
			for (int j=0,len=a.size(); i<len; i++)
			{
				arr[i][id(a[j])] = 1;
			}
			for (int j=0,len=b.size(); i<len; i++)
			{
				arr[i][id(b[j])] = -1;
			}
			
			if (k=="even") t[i] = 0;
			else if (k=="up") t[i] = 1;
			else if (k=="down") t[i] = -1;
		}
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<30; j++)
			{
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}

		for (int i=0; i<3; i++)
		{
			cout << t[i] << ' ';
		}
		cout << '\n';
	}
}
