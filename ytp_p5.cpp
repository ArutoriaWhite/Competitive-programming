#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define id(x) (x-'A')
using namespace std;
typedef pair<int,int> Pii;
const int N = 26;
vector<int> adj[N];

string s, q, res;
int n, vis[30];

void dfs (int u)
{
    res += char('A'+u);
    vis[u] = 1;
    for (auto v: adj[u])
        if (!vis[v]) dfs(v);
}

int main()
{
    cin >> s >> q;
    n = s.size();
    int p = -1;
    for (int i=0; i<26; i++)
        for (p++; p<n&&s[p]!=','; p++)
            adj[id(s[p])].push_back(i);
    for (int i=0; i<q.size(); i++)
    {
        res = "";
        memset(vis,0,sizeof(vis));
        dfs(id(q[i]));
        sort(res.begin(), res.end());
        cout << res << '\n';
    }
}
/*
IF,YOU,DO,NOT,KNOW,HOW,TO,SOLVE,THIS,QUESTION,PLEASE,TRY,TO,USE,DEPTH,FIRST,SEARCH,WISH,YOU,HAVE,FUN,IN,THE,YTP,EXAM,OKAY
WINYTPGAME
*/