#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define isNum(c) ('0'<=c&&c<='9')
#define isAlph(c) ('a'<=c&&c<='z')
using namespace std;
typedef pair<int,int> Pii;

string s;
int x, i, w, l, r, n;
char un;

inline int readNum (int &i)
{
    if (s[i]=='-'&&!isNum(s[i+1])) return -1;
    int k = 1, res=0;
    if (s[i]=='+') k = 1, i++;
    else if (s[i]=='-') k = -1, i++;
    for ( ; i<n&&isNum(s[i]); i++)
    {
        res *= 10;
        res += s[i]-'0';
    }
    return res*k;
}

int main()
{
    Eriri
    cin >> s;
    n = s.size();
    w = 1;

    while (i<n)
    {
        if (s[i] == '+' || s[i]=='-' || isNum(s[i]))
        {
            x = readNum(i)*w;
            if (isAlph(s[i])) un=s[i], l += x, i++;
            else r += -1*x;
        }
        else if (s[i] == '=')
        {
            w = -1, i++;
        }
        else if (isAlph(s[i]))
        {
            un=s[i], l += 1*w, i++;
        }
    }
    cout << fixed << setprecision(3) << un << '=' << (double)r/l << '\n';
}