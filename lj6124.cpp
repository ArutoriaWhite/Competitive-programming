#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;

int n, cnt;
queue<string> q;

inline bool avai (string &s)
{

}

string bfs()
{
    q.push("0");
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        if (q.back() == "1")
        {
            cnt++;
            if (cnt == n)
            {
                return s;
            }
        }
        q.push(s+"0");
        if (avai(s+"1"))
            q.push(s+"1");
    }
}

signed main()
{
    cin >> n;
    cou << bfs() << '\n';
}
