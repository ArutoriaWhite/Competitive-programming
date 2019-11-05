#include<iostream>
using namespace std;
#define maxN 1000000

int p[maxN];
int s[maxN], m[maxN], id[maxN], r=0;

int n[maxN], k[maxN], q[maxN], ans[maxN][2], qr=0;

int gcd( int a, int b)
{
	while (b!=0)
	{
		int tmp=b;
		b=a%b,a=tmp;
	}
	return a;
}

int main()
{
	for (int i=0; i<=1000; i++)
	{
		for (int j=1; j<=i; j++)
		{
			if (gcd(i,j)!=1) continue;
			s[r]=j, m[r++]=j;
			p[i]=r;
		}
	}

	while (cin >> n[qr] >> k[qr])
	{
		q[qr] = qr;
		qr++;
	}
	
	int j=0;
	for (int i=0; i<qr; i++)
	{
		if (n[i]!=j)
		{
			j=n[i];
			sort(id,id+pos[j]);
		}
		ans[q[i]][0] = k[
	}
}
