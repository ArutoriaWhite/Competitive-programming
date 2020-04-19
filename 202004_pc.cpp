#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e6+10;

int to[N], from[N], pos, r;
char cont[N];

inline void init()
{
    r=1;
}
inline void ins (char c)
{
    cont[r] = c;
    from[to[pos]] = r;
    to[r] = to[pos];
    from[r] = pos;
    to[pos] = r;
    r++, pos=to[pos];
}

inline void lshift()
{
    pos = from[pos];
}
inline void rshift()
{
    pos = to[pos];
}
inline void back()
{

}
inline void del()
{

}
inline void print()
{
    for 
}

int main()
{
    cin >> opr;
    for (int i=0; i<opr; i++)
    {
        if (opr[i] == 'L') lshift();
        if (opr[i] == 'R') rshift();
        if (opr[i] == 'B') back();
        if (opr[i] == 'D') del();
    }
}
