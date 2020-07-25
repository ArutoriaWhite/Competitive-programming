#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define exit {flag = 1; return 0;}
using namespace std;
typedef pair<int,int> Pii;

string s;
int t, flag;

inline int calc (int a, int b, int c)
{
    if (c == 0) return a+b;
    if (c == 1) return a-b;
    if (c == 2) return a*b;
    if (c == 3)
    {
        if (b == 0 || a%b) exit
        else
        {
            return a/b;
        }
    }
}

inline int sol (int &i)
{
    if (s[i] == '(')
    {
        int a, b, c;
        
        if (s[i] != '(' && (s[i]<'0' || s[i]>'9'))
        a = sol(++i);
        if (s[i] != ',') exit
        if (s[i] != '(' && (s[i]<'0' || s[i]>'9')) exit        
        b = sol(++i);
        if (s[i] != ',') exit
        if (s[i] != '(' && (s[i]<'0' || s[i]>'9')) exit        
        c = sol(++i);
        if (s[i] != ')') exit            
        ++i;
        return calc(a,b,c); 
    }

    if (s[i] == '+' && ++i) return 0;
    if (s[i] == '-' && ++i) return 1;
    if (s[i] == '*' && ++i) return 2;
    if (s[i] == '/' && ++i) return 3;
    if ('0'<=s[i] && s[i]<='9')
    {
        int res = 0;
        for ( ; '0'<=s[i] && s[i]<='9'; i++)
            res *= 10, res += s[i] - '0';
        return res;        
    }
    flag = 1;
    return 0;
}

signed main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> s;
        flag = 0;
        int i = 0;
        int ans = sol(i);
        if (flag) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}

