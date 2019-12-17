#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int maxM = 1e7+10, maxN = 1e3+10;

int team[maxM], t;
queue<int> q, q2[maxN];
inline void init()
{
	t=1;
	memset(team,-1,sizeof(team));
	while (!q.empty())
		q.pop();
	for (int i=0; i<maxN; i++)
		while (!q2[i].empty())
			q2[i].pop();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, T=0;
	while (cin >> n)
	{
		cout << "Line #" << ++T << "\n";
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
		
		string cmd;
		int x;
		while (cin >> cmd)
		{
			if (cmd[0] == 'E')
			{
				cin >> x;
				if (team[x] == -1)
					q.push(-x);
				else if (q2[team[x]].empty())
					q.push(team[x]);
				q2[team[x]].push(x);
			}
			else if (cmd[0] == 'D')
			{
				if (q.front()<0)
				{
					cout << -q.front() << '\n';
					q.pop();
					continue;
				}
				cout << q2[ q.front() ].front() << '\n';
				q2[ q.front() ].pop();
				if (q2[q.front()].empty()) q.pop();
			}
			else break;
		}
	}
	return 0;
}