#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5;
int to[N], from[N], val[N], r, cnt;

void push_back (int x)
{
    ++cnt;
    val[cnt] = x;
    to[r] = cnt;
    from[cnt] = r;
    r = cnt;
}
void push_front (int x)
{
    if (r==0) push_back(x);
    else
    {
        ++cnt;
        val[cnt] = x;
        to[cnt] = to[0];
        from[to[0]] = cnt;
        to[0] = cnt;
    }
}
void print()
{
    for (int i=0,j=to[0]; j!=0; i=j,j=to[j])
        cout << val[j] << '\n';
}
void pop_back()
{
    to[ from[r] ] = 0;
    r = from[r];
}
void pop_front()
{
    to[0] = to[to[0]];
    from[to[0]] = 0;
}
