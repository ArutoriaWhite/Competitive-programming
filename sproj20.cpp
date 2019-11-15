#include<iostream>
#include<string.h>
using namespace std;
#define maxN (10000000)
#define maxM (1000+10)

int bigq[maxN], bigf, bigr;
int smalq[maxN][50], f[maxM], r[maxM];
int alon[maxN];
int inq[maxN];
int t=0;

inline void enq( int x)
{
	if (inq[alon[x]]<t)
	{
		bigq[bigr++] = alon[x];
		inq[alon[x]] = t;
	}
	smalq[alon[x]][r[alon[x]]++] = x;
}

inline int deq()
{
	int *q = smalq[bigq[bigf]];
	cout << q[f[bigq[bigf]]++] << '\n';
	if (f[bigq[bigf]] >= r[bigq[bigf]])
	{
		inq[bigq[bigf++]] = 0;
	}
}

inline void init()
{
	bigf = 0;
	bigr = 0;
	memset(f,0,sizeof(f));
	memset(r,0,sizeof(r));
	for (int i=0; i<maxN; i++)
		alon[i] = i;
}
inline void print()
{
	for (int i=0; i<bigr; i++)
	{
		for (int j=0; j<r[bigq[i]]; j++)
		{
			cout << smalq[bigq[i]][j] << ' '; 
		}
		cout << '\n';
	}
	cout << '\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n)
	{
		t++;
		init();
		for (int i=0; i<n; i++)
		{
			int k, x0;
			cin >> k >> x0;
			for (int j=1; j<k; j++)
			{
				int x;
				cin >> x;
				alon[x] = x0;
			}
		}
		cout << "Line #" << t << "\n";
		string opr;
		while (cin >> opr)
		{
			if (opr=="ENQUEUE")
			{
				int x;
				cin >> x;
				enq(x);
			}
			else if (opr=="DEQUEUE")
			{
				deq();
			}
			else
			{
				break;
			}
		}
	}
}

