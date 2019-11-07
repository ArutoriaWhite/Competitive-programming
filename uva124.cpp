#include<iostream>
#include<string.h>
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
		}
		getline(cin,s);
		for (int i=0,len=s.size(); i<len; i+=4)
		{
			int a = id(s[i]),  b = id(s[i+2]);
			pre[b] |= (1<<a);
		}
		
		ans[0] = '\0';
		DFS(0,0);
	}
}
