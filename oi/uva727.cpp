#include<iostream>
#include<cstdlib>
using namespace std;
#define maxN 100
#define DE cout << " ::"

int stk[maxN], calc[maxN];
int rs, rc;
bool isopr[maxN];
int pri[150];

inline void init()
{
	rs=0, rc=0;
	pri['('] = 0;
	pri[')'] = 1;
	pri['+'] = 2;
	pri['-'] = 2;
	pri['*'] = 3;
	pri['/'] = 3;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string x;
		while (cin>>x)
		{
			if (x[0]=='+'||x[0]=='-'||x[0]=='*'||x[0]=='/'||x[0]=='('||x[0]==')')
			{
				while (rs>0 && pri[stk[rs-1]]>=pri[x[0]])
				{
					calc[rc] = stk[--rs];
					isopr[rc++] = 1;
				}
				if (rs>0 && stk[rs-1]==(int)'(' && x[0]==')')
				{
					rs--;
				}
				else stk[rs++] = x[0];
			}
			else
			{
				calc[rc] = atoi(&x[0]);
				isopr[rc++] = 0;
			}
			DE << rs << '\n';
		}
		for( int i=0; i<rc; i++)
		{
			if (isopr[i]) cout << (char)calc[i];
			else cout << calc[i];
		}
		cout << '\n';
	}
}
