#include<iostream>
#include<algorithm>
using namespace std;
#define maxN 1000000
#define DE cout << " ::"

int s[maxN], m[maxN], nid[maxN], r=0, pos[maxN]; // son, mother
int n[maxN], k[maxN], qid[maxN], anss[maxN], ansm[maxN], r2=0;

inline bool cmp( int a, int b)
{
	return n[a]<n[b];
}
inline bool cmp2( int a, int b)
{
	return ((double)(s[a]))/(m[a]) < ((double)(s[b]))/(m[b]); 
}
inline int gcd( int a, int b)
{
	while (b!=0)
	{
		int tmp=a;
		a = b;
		b = tmp%b;
	}
	return a;
}

int main()
{
	for (int i=0; i<maxN; i++)
		qid[i] = i, nid[i] = i;
	while (cin >> n[r2] >> k[r2++]);
	r2--;

	sort(qid,qid+r2,cmp);
	
	for (int i=1; i<=1000; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if (gcd(i,j)!=1) continue;
			pos[i] = r;
			s[r] = j;
			m[r++] = i;
		}	
	}

	for (int i=0; i<r2; i++)
	{
		sort(nid, nid+pos[n[qid[i]]]+1, cmp2);
		anss[qid[i]] = s[nid[k[qid[i]]-1]];
		ansm[qid[i]] = m[nid[k[qid[i]]-1]];
	}
	for (int i=0; i<r2; i++)
	{
		cout << anss[i] << '/' << ansm[i] << '\n';
	}
}
