#include <bits/stdc++.h>
using namespace std;
#define maxN 10005
#define rep(i,a,b) for(int i=(a) ; i<(b) ; i++ )
typedef pair<int,int> pii;

vector<pii> edges[maxN];
int dis[maxN];

void dijks( int rt ){
    memset( dis, 0x3f3f3f3f, sizeof(dis)); dis[rt] = 0;
    priority_queue< pii, vector<pii>, greater<pii>> pq;
    pq.push( pii(0,rt));

    while( !pq.empty()){
        int  u = pq.top().second, d = pq.top().first;
        pq.pop();
        if( dis[u] < d) continue;

        for( auto v: edges[u]){ //relaxation
            if( dis[v.second] > d+v.first){
                dis[v.second] = d+v.first;
                pq.push( make_pair( dis[v.second], v.second));
            }
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);

    int n,m,rt; cin >> n >> m >> rt;
    rep(i,0,m){
        int a,b,w; cin >> a >> b >> w;
        edges[a-1].push_back( make_pair(w,b-1));
    }
    dijks(rt-1);
    rep( i, 0, n) cout << dis[i] << ' '; 
    return 0;
}

/*
6 9
1
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/