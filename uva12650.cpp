#include<iostream>
using namespace std;

int arr[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, u;
	while (cin >> n >> r)
	{
		u++;
		for (int i=1; i<=r; i++)
		{
			int x;
			cin >> x;
			arr[x] = u;
		}
		
		bool flag=1;
		for (int i=1; i<=n; i++)
		{
			if (arr[i]<u)
			{
				flag=0;
				cout << i << ' ';
			}
		}
		if (flag)
		{
			cout << "*";
		}
		cout << '\n';
	}
	return 0;
}

