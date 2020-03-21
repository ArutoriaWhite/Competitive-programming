#include<iostream>
#include<memory.h>
using namespace std;
const int N=1e8, M=3e3+10;

int res[N], r;
int ap[M];

inline void init
{
	r=0;
	memset(ap,-1,sizeof(ap));
}

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		cout << x << "/" y << " = " << x/y << ".";
		x=x%y;
		int s=-1, t=-1;
		while (x!=0)
		{
			
		}
	}
}
