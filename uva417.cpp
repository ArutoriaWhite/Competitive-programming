#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;

/*
bfs gen map<string,int>
*/

unordered_map<string,int> mp;
queue<string> q;
int cnt = 0;

void bfs()
{
    for (char c='a'; c<='z'; c++)
        q.push((string)"" + c);
    while (!q.empty())
    {
        string s = q.front(); q.pop();
        mp[s] = ++cnt;
        if (s.size() >= 5) continue;
        for (char c=s.back()+1; c<='z'; c++)
            q.push(s+c);
    }
}

signed main()
{
    Eriri
    string s;
    bfs();
    while (cin >> s)
    {
        cout << mp[s] << '\n';
    }
}
