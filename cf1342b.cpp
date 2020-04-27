#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string s;
int t;

inline bool all_same()
{
    for (int i=0,len=s.size(); i<len; i++)
        if (s[i]!=s[0]) return 0;
    return 1;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (all_same()) cout << s << '\n';
        else
        {
            for (int i=0,len=s.size(); i<len; i++)
            {
                cout << "10";
            }
            cout << '\n';
        }
    }
}