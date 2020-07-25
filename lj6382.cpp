#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int a[10];
string s;

inline int tail()
{
    for (int i=s.size()-1; i>=0; i--)
    {
        if ('0'<=s[i] && s[i]<='9')
        {
            return s[i]-'0';
        }
    }
}

int main()
{
    cin >> s;
    if (s[0]!='M'||s[1]!='D'||s[2]!='A')
    {
        for (int i=1; i<=5; i++) a[i] = 1;
    }
    else
    {
        int k = tail();
        if (k==1 || k==9)
            a[1] = 1;
        if (k==2 || k==8)
            a[2] = 1;
        if (k==3 || k==7)
            a[3] = 1;
        if (k==4 || k==6)
            a[4] = 1;
        if (k==5 || k==0)
            a[5] = 1;
    }
    for (int i=1; i<=5; i++)
        cout << a[i] << ' ';
    cout << '\n';
}