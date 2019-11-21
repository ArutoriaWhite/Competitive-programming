#include<iostream>
using namespace std;
#define maxN (10000000+10)

int arr[maxN], tmp[maxN];

struct data
{
	int res, qsum;
};

inline int merg (int l, int r, int sum)
{
	int m=(l+r)>>1;
	int i=l, j=m, rear=l, res=0;
	while (i<m || j<r)
	{
		if (j<r && arr[j]<arr[i] || i>=m)
		{
			tmp[rear++] = arr[j];
			j++, res += sum + max(0,(m-i))*arr[j];
		}
		else
		{
			tmp[rear++] = arr[i];
			i++, sum -= arr[i];
		}
	}
	for (int i=l; i<rear; i++)
		arr[i] = tmp[i];
	return res;
}

data msort (int l, int r)
{
	if (r-l<=1) return data{0,arr[l]};
	int m = (l+r)>>1;
	data x=msort(l,m), y=msort(m,r);
	return data{ merg(l,r,x.qsum), x.qsum+y.qsum};
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i=0; i<n; i++)
			cin >> arr[i];
		cout << msort(0,n).res << '\n';
		for (int i=0; i<n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}	
}
