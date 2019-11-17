#include<iostream>
using namespace std;
#define maxN 100000
#define LOG 30

int arr[maxN], sp[LOG][maxN];
inline void build( int n)
{
	for (int i=0; i<n; i++)
		sp[i] = arr[i];

	for (int j=1; (1<<j)<=n; j++)
		for (int i=0; (i+(1<<j))<n; i++)
			sp[j][i] = min (sp[j-1][i], sp[j-1][i+(1<<j-1)];
}
inline int query( int a, int b)
{
	int k;
	for (k=0; (1<<k)<(b-a+1); k++);
	return min (sp[k][a], sp[k][b-(1<<k)+1]);
}


