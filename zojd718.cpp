#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int maxM = 1e7+10, maxN = 1e3+10;

int team[maxM], t;
inline void init()
{
	t=1;
	memset(team,-1,sizeof(team));
}

int main() {
	int n;
	while (cin >> n)
	{
		init();
		for (int i=1; i<=n; i++)
		{
			int m;
			cin >> m;
			for (int j=0; j<m; j++)
			{
				int x;
				cin >> x;
				team[x] = t;
			}
			t++;
		}
		
		queue<int> q, q2[maxN];
		string cmd;
		int x;
		while (cin >> cmd)
		{
			if (cmd[0] == 'E')
			{
				cin >> x;
				if (team[x] == -1)
					team[x] = t++;
				if (q2[team[x]].empty())
					q.push(team[x]);
				q2[team[x]].push(x);
			}
			else break;
		}
				
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			while (!q2[u].empty())
			{
				cout << q2[u].front() << ' ';
				q2[u].pop();
			}
			cout << ':';
		}
		cout << '\n';
	}
	return 0;
}
