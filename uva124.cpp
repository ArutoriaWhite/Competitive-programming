#include<iostream>
#include<string.h>
<<<<<<< HEAD
using namespace std;
#define maxN 30
#define ti(x) (x-'a'+1)

int to[maxN], pre[maxN];

int main()
{
	string s;
	while (getline(cin,s))
	{
		memset(to,0,sizeof(to));
		memset(pre,0,sizeof(pre));
		int j=0;
		for (int i=0,len=s.size(); i<len; i+=2)
		{
			to[j] = ti(s[i]);
			j = to[j];
=======
#include<algorithm>
using namespace std;
#define maxN 30
#define id(x) (x-'a'+1)

int pre[maxN], to[maxN], n;
char ans[30];

void DFS( int used, int dep)
{
	if (dep==n)
	{
		cout << ans << '\n';
	}

	for (int i=0,j=to[i]; j!=0; i=j,j=to[j])
	{
		if ((pre[j]&used) == pre[j])
		{
			used |= (1<<j);
			ans[dep] = (char)('a'+j-1);
			to[i] = to[j];
			DFS(used,dep+1);
			to[i] = j;
			ans[dep] = '\0';
			used -= (1<<j);
		}
	}
}

inline void init()
{
	memset(to,0,sizeof(to));
	memset(pre,0,sizeof(pre));
	n=0;
}

int main()
{
	bool fir=1;
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (getline(cin,s))
	{
		if (fir) fir=0;
		else cout << '\n';
		init();

		int tmp[30];
		for (int i=0,j=0,len=s.size(); i<len; i+=2,j++)
		{
			tmp[j] = id(s[i]);
			n++;
		}
		sort(tmp,tmp+n);
		for (int i=0,j=0; i<n; i++,j=to[j])
		{
			to[j] = tmp[i];
>>>>>>> bf50d8261208c5825078bc44f1559e30f78a5e35
		}
		getline(cin,s);
		for (int i=0,len=s.size(); i<len; i+=4)
		{
<<<<<<< HEAD
			int a=ti(s[i]), b=ti(s[i+3]);
			pre[b] |= (1<<a);
		}

		char a, b;
		while (cin >> a >> b)
		{
			cout << (pre[ti(b)])&(1<<a) << '\n';
		}
	}

=======
			int a = id(s[i]),  b = id(s[i+2]);
			pre[b] |= (1<<a);
		}
		
		ans[0] = '\0';
		DFS(0,0);
	}
>>>>>>> bf50d8261208c5825078bc44f1559e30f78a5e35
}
