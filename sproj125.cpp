#include<iostream>
using namespace std;
#define maxN (10000000+10)
#define M 10000019
#define int long long

int arr[maxN], tmp[maxN];
struct data
{
	int sum, res;
};

int mer (int l, int r, int lsum)
{
	int m=(l+r)>>1, i=l, j=m, rear=l, res=0;
	while (i<m || j<r)
	{
		if (i>=m || (j<r && arr[j]<arr[i]))
		{
			res = ((((arr[j]*(m-i))%M) + lsum)%M + res)%M;
			tmp[rear++] = arr[j++];
		}
		else
		{
			lsum -= arr[i];
			tmp[rear++] = arr[i++];
		}
	}
	for (int i=l; i<rear; i++)
		arr[i] = tmp[i];
	return res%M;
}

data msort (int l, int r)
{
	if (r-l<=1) return data{arr[l],0};
	int m = (l+r)>>1;
	data a=msort(l,m), b=msort(m,r);
	return data{ a.sum+b.sum, (((mer(l,r,a.sum))%M+a.res)%M+b.res)%M};
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	cout << msort(0,n).res << '\n';
	return 0;
}
