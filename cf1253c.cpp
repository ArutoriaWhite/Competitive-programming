#include<iostream>
<<<<<<< HEAD
using namespace std;
#define maxN (200000+10)
#define LS(i) (i<<1)
#define RS(i) (i<<1|1)

int arr[maxN], ans[maxN];
// seg
int l[maxN], r[maxN], val[maxN];

inline void pull (int i)
{
	val[i] = val[LS(i)] + val[RS(i)];
}
void build (int i, int al, int ar)
{
	l[i]=al, r[i]=ar;
	if (al==ar)
	{
		val[i] = arr[l[i]];
		return;
	}
	int m=(l[i]+r[i])>>1;
	build(LS(i),l[i],m);
	build(RS(i),m+1,r[i]);
	pull(i);
}
int query (int i, int ql, int qr)
{
	if (ql<=l[i]&&r[i]<=qr) return val[i];

	int res=0, m=(l[i]+r[i])>>1;
	if (ql<=m) res += query(LS(i),ql,qr);
	if (qr>m)  res += query(RS(i),ql,qr);
	return res;
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	for (int i=1; i<=m; i++)
	{
		int res= query(0,i-1);
		for (int j=i,k=0; j<n; j+=m)
		{
			res += query(k,j-1);
		}
	}
	
}

// seg t
// 
=======
#include<algorithm>
using namespace std;
#define maxN (200000+10)

int arr[maxN], n, m;
long long sum[maxN], ans[maxN];

inline void build()
{
	sort(arr,arr+n);
	for (int i=1; i<=n; i++)
		sum[i] = sum[i-1]+arr[i-1];	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	build();

	for (int i=1; i<=m; i++)
	{
		int d=0;
		long long s=0;
		for (int j=i; j<=n; j+=m)
		{
			s += sum[j];
			ans[j]=s;
		}
	}
	
	for (int i=1; i<=n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
>>>>>>> 66102d04d147b49c7758bf9845382e2f94392d73
