#ifndef EVAL
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int Answer(int N,int P,int *H,int *L,int *R,int *V);

int main()
{
	const int maxN = 1000000;
	const int maxP = 1000000;
	int *H = new int[maxN];
	int *L = new int[maxP];
	int *R = new int[maxP];
	int *V = new int[maxP];
	int N,P;
	while( cin>>N>>P )
	{
		for(int i=0;i<N;++i)
			cin>>H[i];
		for(int i=0;i<P;++i)
			cin>>L[i]>>R[i]>>V[i];
		cout<<Answer(N,P,H,L,R,V)<<endl;
	}
}
#endif
#include <iostream>
using namespace std;

const int maxN = 1e6+10;
long long pre[maxN], ans, mx = -1e18, mn = 1e18;

int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
	for (int i=0; i<P; i++)
		pre[L[i]-1] += V[i];
	for (int i=0; i<P; i++)
		pre[R[i]] -= V[i];
	for (int i=0; i<N; i++)
	{
		pre[i] = pre[i-1] + pre[i];
		mx = max(mx, pre[i] + H[i]);
		mn = min(mn, pre[i] + H[i]);
	}
	return mx - mn;
}
/*
5 3
0 0 1 0 1
1 3 1
2 5 -1
1 1 2
*/