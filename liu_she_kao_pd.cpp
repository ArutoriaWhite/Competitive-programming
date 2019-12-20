#include<iostream>
#include<cstring>
using namespace std;
const int N=110;

inline init ( int *n, string &s)
{
	for (int i=0; i<N; i++)
		n[i] = 0;
	for (int i=0,j=s.size()-1; j>=0; i++,j--)
		n[i] = s[j]-'0';
}

inline void minu (int *a, int *b, int *res)
{
	int bor=0;
	for (int i=0; i<N; i++)
	{
		res[i] = a[i]-b[i]-bor;
		if (a[i]-b[i]<0)
			bor = 1, res[i]+=10;
		else
			bor = 0;
	}
}

inline void muti (int *a, int *b, int *res)
{
	int car=0;
	for (int i=0; i<N; i++)
	{
		res[i] = a[i]*b[i]+car;
		if (res[i]>=10)
			car=res[i]/10, res[i]%=10;
		else
			car=0;
	}
}

inline void print (int *n)
{
	bool beg=0;
	int i;
	for (i=N-1; n[i]==0&&i>=0; i--);
	for (i; i>=0; i--)
		cout << n[i];
	cout << '\n';
}

int main()
{
	int a[N], b[N], c[N];
	string x, y;
	while (cin >> x >> y)
	{
		init(a,x);
		init(b,y);
		muti(a,b,c);
		print(c);
	}
}
