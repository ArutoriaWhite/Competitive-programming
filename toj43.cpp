#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define maxN 10005
#define rep(i,a,b) for(int i=(a) ; i<(b) ; i++ )

typedef pair<int,int> pii;

vector<pii> edges[maxN];
int dis[maxN];

void dijks( int rt ){
    memset( dis, 0x3f3f3f3f, sizeof(dis)); dis[rt] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push( pii(0,rt));

    while( !pq.empty()){
        int  u = pq.top().second, d = pq.top().first;
        pq.pop();
        if( dis[u] < d) continue;

        for( auto v: edges[u]){
            if( dis[v.second] > d+v.first){
                dis[v.second] = d+v.first;
                pq.push( make_pair( dis[v.second], v.second));
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
		int a, b, L;
		cin >> a >> b >> L;
		edges[a].push_back(make_pair(L,b));
		edges[b].push_back(make_pair(L,a));
	}
	int s, e;
	cin >> s >> e;
	dijks(s);
	cout << dis[e] << '\n';
}
