#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
int const N=1e3+10;

int mp[200];

int colo[N][N], n;
struct ele { int col, x, y, d; };
queue<ele> q;
int num[10], res, qcol;

inline void init()
{
    while (q.empty())
        q.pop();
    memset(num,0,sizeof(num));
    res=-1e9;
}

inline int bfs()
{
    while (!q.empty())
    {
        
    }
}

int main()
{
    mp['R']=4, mp['Y']=2, mp['B']=1;
    mp['O']=mp['R']|mp['Y'];
    mp['P']=mp['R']|mp['B'];
    mp['G']=mp['Y']+my['B'];
    mp['D']=mp['R']|mp['Y']|mp['B'];

    int T, x, y,,
    char c;
    cin >> T;
    while (T--)
    {
        init();
        cin >> n;
        for (int i=0; i<3; i++)
        {
            cin >> c >> x >> y;
            q.push( {mp[c], x, y, 0} );
        }
        cin >> qcol;
        cout << bfs() << '\n';
    }
}