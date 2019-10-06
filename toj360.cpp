###### tags: 'Books'#include <bits/stdc++.h>
using namespace std;
#define DE cout<<" ::"

int amnt;
int adjM[9][9];

int vis[9];
int path[10000];

void DFS( int u, int dep){

    if( dep+1>=amnt){
        for( int i=0; i<=dep; i++){
            cout << path[i];
        }
        cout << '\n';
        return;
    }

    for( int v=0; v<9; v++){
        if( !adjM[u][v] || vis[v]) continue;


        path[dep+1]=v;
        DFS( v, dep+1);
    }


}

int main(){
#ifdef local
    freopen( "in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie (0);
#endif

    int n; cin>>n;
    unordered_set<int> nodes;

    for( int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        a--, b--;
        nodes.insert(a);
        nodes.insert(b);
        adjM[a][b]=1;
        adjM[b][a]=1;
    }
    for( int a=0; a<9; a++){
        for( int b=0; b<9; b++){
            if( adjM[a][b] || (a+b)&1) continue;
            adjM[a][b] = adjM[a][(a+b)>>1] && adjM[(a+b)>>1][b];
        }
    }

    amnt=nodes.size();
    //*
    for( int v=0; v<9; v++){
        path[0]=v;
        vis[v]=1;
        DFS( v, 0);
        vis[v]=0;
    }
    //*/
}
/*
DFS:
    end: vis all
    print: vis all
vis:
    add mid node
*/

