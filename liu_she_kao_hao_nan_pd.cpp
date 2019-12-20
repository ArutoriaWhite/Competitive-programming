#include<iostream>
#include<cstring>
using namespace std;
const int N=110;

inline void init ( int *n, string s)
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
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			res[i+j] += a[j]*b[i];
	int car = 0;
	for (int i=0; i<N; i++)
	{
		res[i]+=car;
		car = res[i]/10;
		res[i]%=10;
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

int excalibur[N], calibur[N], fuck[N];

int main()
{
	int *a, *b, *res;
	a = excalibur;
	b = calibur;
	res = fuck;
	
	string n, m;
	cin >> n >> m;
	
	init(a,m);
	init(b,"1");
	init(res,"0");
	minu(a,b,res);
	swap(res,a);
	
	init(b,m);
	init(res,"0");
	muti(a,b,res);
	swap(res,a);
	
	init(b,"2");
	init(res,"0");
	muti(a,b,res);
	
	print(res);
}
