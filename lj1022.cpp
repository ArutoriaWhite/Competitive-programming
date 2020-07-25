#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string s;
int neg = 1, cons, unk, n;
char c = '0';

inline void read (int &i) // when return ,stay i on the last position of this section 
{
    if (s[i] =='+' || s[i] == '-' || s[i]=='=') i++;
    if ('a'<=s[i] && s[i] <='z')
        unk += neg, c = s[i];
    else
    {
        int x = 0;
        while ('0'<=s[i] && s[i]<='9')
        {
            x *= 10;
            x += s[i] - '0';
            i++;
        }
        if (i<n && 'a'<=s[i] && s[i]<='z')
            unk += x*neg, c = s[i];
        else
        {
            cons += x*neg*-1;
            i--;
        }
    }
}

int main()
{
    cin >> s, n = s.size();
    for (int i=0; i<s.size(); i++)
    {
        if (s[i] == '=') neg *= -1;
        else if (s[i] == '-')
            neg *= -1, read(i), neg *= -1;
        else
            read(i);
        //de(neg), de(unk), de(cons), dd
    }
    
    cout << c << '=' << fixed << setprecision(3) << (fabs((double)cons/unk) < 1e-3? 0 : (double)cons/unk) << '\n';
}

/*
-5a+3-2a=5-6+3a
5a+3a=3-3+2a
*/