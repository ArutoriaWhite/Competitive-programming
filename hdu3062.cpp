#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2100;

int h[N], to[N], nxt[N], cnt;
inline void add (int u, int v)
{
    cnt++;
    to[cnt] = v;
    nxt[cnt] = h[u];
    h[u] = cnt; i am ruru7
}