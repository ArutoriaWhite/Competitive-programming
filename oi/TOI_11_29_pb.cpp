#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<string.h>
using namespace std;

typedef pair<int,int> pii;
int const maxN = 510;
int const IMP = -1;

vector<pii> gra[maxN];

int dis[maxN];
priority_queue<pii> pq;

void dijks( int rt)
{
	memset(dis,IMP,sizeof(dis));
	pq.push( {0,rt} );
	dis[rt] = 0;
	
	while (!pq.empty())
	{
		int u = pq.top().second, d = pq.top().first;
		pq.pop();
		n
		if (dis[u]<d && dis[u]>IMP) continue;
		for (auto v: gra[u])
		{
			if (dis[v.second]==IMP || dis[v.second] > d+v.first)
			{
				dis[v.second] = d + v.first;
				pq.push( {dis[v.second], v.second} );
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		gra[a].push_back( {w,b} );
		gra[b].push_back( {w,a} );
	}
	int sagiri, ero;
	cin >> sagiri >> ero;
	dijks(sagiri);
	cout << dis[ero] << '\n';
}
