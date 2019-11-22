#include<iostream>
using namespace std;
#define N 6
#define M 1000000007
#define int long long
typedef long long akagi[N][N];
typedef long long (*natori)[N];

akagi swit =
{
	{1,1,1,0,0,0},
	{1,0,0,0,0,0},
	{0,1,0,0,0,0},
	{1,1,1,1,1,1},
	{0,0,0,1,0,0},
	{0,0,0,0,1,0}
};
akagi ini =
{
	{1,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,1}
};
akagi m0,m1,m2;

inline void mul (natori a, natori b, natori res)
{
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			res[i][j] = 0;
			for (int k=0; k<N; k++)
				res[i][j] = ((a[i][k]*b[k][j])%M + res[i][j])%M;
		}
	}
}

inline natori qpow (int n)
{
	memcpy(m0,swit,sizeof(m0));
	memcpy(m1,ini,sizeof(m1));
	natori a = m0, res = m1, tmp = m2;
	
	while (n>0)
	{
		if (n&1)
		{
			mul(res,a,tmp);
			swap(res,tmp);
		}
		n>>=1;
		mul(a,a,tmp);
		swap(a,tmp);
	}
	return res;
}

signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		natori p = qpow(n-1);
		
		long long res=0;
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
oo				res = (res+p[i][j])%M;
				
		cout << res << '\n';
	}
}
