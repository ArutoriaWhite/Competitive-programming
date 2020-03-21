#include<iostream>
#include<vector>
#include<tuple>
#include<string.h>
#include<queue>
using namespace std;
#define maxN (10000+10)

typedef pair<int,int> edge;
#define W first
#define X second

typedef pair<int,int> ele;
#define D first
#define X second

vector<edge> gra[maxN];

int dis[maxN];
priority_queue<ele> pq;

void dijks( int rt)
{
	memset(dis,0x3f,sizeof(dis));
	pq.push( ele(0,rt) );

	while (!pq.empty())
	{
		ele u = pq.top();
		pq.pop();

		if (dis[u.X] < u.D) continue;
		for (auto v: gra[u.X])
		{
			if (dis[v.X] > u.D+v.W) 
			{
				dis[v.X] = u.D+v.W;
				pq.push( make_pair( dis[v.X], v.X ) );
			}
		}
	}
}

int main ()
{
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		gra[a].push_back( make_pair(c,b) );
		gra[b].push_back( make_pair(c,a) );
	}

	int oao, tat;
	cin >> oao >> tat;
	dijks(oao);
	cout << dis[tat] << '\n';
}
