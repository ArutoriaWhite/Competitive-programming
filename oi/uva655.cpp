#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define maxN (100+10)

int mob[maxN][maxN], typ[maxN];
inline void init()
{
	memset(mob,0,sizeof(mob));
	memset(typ,0,sizeof(typ));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		init();
		int n, k, res=0;
		cin >> n >> k;
		for (int i=0; i<k; i++)
		{
			int p;
			cin >> p;
			for (int j=0; j<p; j++)
			{
				int x;
				cin >> x;
				mob[i][x] = 1;
			}
			for (int j=0; j<p; j++)
			{
				int x;
				cin >> x;
				mob[i][x] = -1;
			}
			char opr;
			cin >> opr;
			if (opr=='<') typ[i] = -1;
			else if (opr=='>') typ[i] = 1;
			else typ[i] = 10;
		}
		
		for (int i=1; i<=n; i++)
		{
			int pre;
			bool flag=1;
			for (int j=0; j<k; j++)
			{
				int cur = mob[i][j]*typ[j];
				if ((abs(cur)>1) || (cur!=pre&&j!=0))
				{
					flag=0;
					break;	
				}
				pre = cur;
			}
			if (flag)
			{
				if (res!=0)
				{
					cout << "0\n";
					res = -1;
					break;
				}
				else
					res=i;
			}
		}
		if (res!=-1) cout << res << '\n';
	}
}

