#include<iostream>
#include<algorithm>
using namespace std;
#define maxN 10000010

int q[maxN], ord[maxN], arr[maxN];

int ty[maxN];
int l[maxN],r[maxN];

inline bool cmp( int a, int b)
{
	return q[a]<q[b];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	int t;
	cin >> t;
	for (int i=0; i<t; i++)
	{
		cin >> q[i];
		ord[i] = i;
	}
	
	sort( arr, arr+n);
	sort( ord, ord+t, cmp);
	
	int j=0;
	for (int i=0; i<t; i++)
	{
		if (q[ord[i]]<arr[0])
		{
			ty[ord[i]] = 1;
		}
		else if(q[ord[i]]>arr[n-1])
		{
			ty[ord[i]] = -1;
		}
		else
		{
			while (arr[j]<q[ord[i]])
			{
				j++;
			}
			if (arr[j]>q[ord[i]])
			{
				ty[ord[i]] = 0;
				l[ord[i]] = arr[j-1];
				r[ord[i]] = arr[j];
			}
			else
			{
				ty[ord[i]] = 2;
				l[ord[i]] = arr[j];
			}
		}
	}
	
	for (int i=0; i<t; i++)
	{
		if (ty[i]==2)
		{
			cout << l[i] << '\n';
		}
		else if (ty[i]==1)
		{
			cout << "no " << arr[0] << '\n';
		}
		else if(ty[i]==0)
		{
			cout << l[i] << ' ' << r[i] << '\n';
		}
		else
		{
			cout << arr[n-1] << " no\n";
		}
	}
}
