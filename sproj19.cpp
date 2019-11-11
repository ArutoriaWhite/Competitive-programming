#include<iostream>
using namespace std;
#define maxN 100010

int l[maxN], r[maxN], bot[maxN];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> l[i];
		for (int i=0; i<n; i++)
			r[i] = i+1;

		bool flag=1;
		for (int i=0,j=0,rear=0; i<n; i++)
		{
			if (rear>0&&(bot[rear-1]==l[i]))
				rear--;
			else if (r[j]<=l[i])
			{
				while (r[j]<l[i])
					bot[rear++] = r[j++];
				j++;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}
}
