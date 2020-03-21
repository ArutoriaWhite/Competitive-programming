#include<iostream>
using namespace std;
#define maxN (10000000+10)
<<<<<<< HEAD

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
=======
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
>>>>>>> da7eaa61c6fefb68242db4e99899b8fbc8ba18d9
		}
	}
	for (int i=l; i<rear; i++)
		arr[i] = tmp[i];
<<<<<<< HEAD
	return res;
=======
	return res%M;
>>>>>>> da7eaa61c6fefb68242db4e99899b8fbc8ba18d9
}

data msort (int l, int r)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> da7eaa61c6fefb68242db4e99899b8fbc8ba18d9
}
