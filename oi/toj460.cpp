#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for( int i=(a); i<(b); i++)
#define GETI (getchar() - '0')
#define DE cout << " ::"

#define PII pair<int,int>
#define FR first
#define SC second

#define N 0
#define W 1
#define E 2
#define S 3
#define DOM 4 // domain

#define INF 0x3f3f3f3f

inline int toHex( char c){
    if( isdigit(c)) return c-'0';
    return (c - 'A'+ 10);
}

PII order[9];
int G[5][5][5];

int main(){
#ifdef local
    freopen( "in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie (0);
#endif
    memset( G, INF, sizeof( G));
    REP( y, 1, 4){
        REP( x, 1, 4)
            order[GETI] = PII( x, y);
        getchar();
    }

    REP( i, 0, 9){
        int x = order[i].FR, y = order[i].SC;
        int *cur = G[x][y];
        cur[DOM] = i&1;
        //DE << i;
        REP( curF, 0, 4){
            cur[curF] = toHex( getchar());
            //DE << cur[curF];
            int *adj, adjF;
            switch(curF){
            case N: adj = G[x][y-1]; adjF = S; break;
            case S: adj = G[x][y+1]; adjF = N; break;
            case W: adj = G[x-1][y]; adjF = E; break;
            case E: adj = G[x+1][y]; adjF = W; break;
            }
            //DE << adj[adjF];
            if( (adj[DOM]^cur[DOM]) && adj[adjF]<=cur[curF]){
                //DE << cur[curF] << ' ' << adj[adjF];
                adj[DOM] = cur[DOM];
            }
        }
        //DE << '\n';
        getchar();
    }

    int amnt[2];
    memset( amnt, 0, sizeof( amnt));
    REP( x, 1, 4){
        REP( y, 1, 4){
            amnt[ G[x][y][DOM] ] ++;
        }
    }
    cout << amnt[0] << '-' << amnt[1] << '\n';









}
