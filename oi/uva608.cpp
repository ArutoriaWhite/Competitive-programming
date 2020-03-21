#include<iostream>
#include<string.h>
using namespace std;
#define id(x) (x-'A')

int arr[3][30], t[3];

int main()
{
	ios::sync_with_stdio(1);
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
			for (int j=0,len=a.size(); j<len; j++)
			{
				arr[i][id(a[j])] = 1;
			}
			for (int j=0,len=b.size(); j<len; j++)
			{
				arr[i][id(b[j])] = -1;
			}
			
			if (k=="even") t[i] = 0;
			else if (k=="up") t[i] = 1;
			else if (k=="down") t[i] = -1;
		}

		for (int j=0; j<='L'-'A'; j++)
		{

			bool flag=1;
			int k=0;
				
			for (int i=0; i<3; i++)
			{
				if (t[i]==0&&arr[i][j]!=0)
				{
					flag=0;
					break;
				}
				if (t[i]!=0&&arr[i][j]==0)
				{
					flag=0;
					break;
				}
				if (t[i]==0&&arr[i][j]==0)
				{
					continue;
				}

				if (k==0)
				{
					k=arr[i][j]*t[i];
				}
				else
				{
					if (k!=t[i]*arr[i][j])
					{
						flag=0;
						break;
					}
					k = t[i]*arr[i][j];
				}
			}
			
			if (flag)
			{
				cout << (char)('A'+j);

				if (k==1)
				{
					cout << " is the counterfeit coin and it is heavy.\n";
				}
				else 
				{
					cout << " is the counterfeit coin and it is light.\n";
				}
				break;
			}

		}
	}
}
// flag=1
// if t[i]==0, arr[i][j]!=0, break;
// if t[i]!=0, arr[i][j]==0, break;
// t[0]*arr[i][j] == ... == t[3]*arr[i][j] expect 0

