#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

string s, t;
int f[N];
void build()
{
    f[0] = -1;
    for (int i=1,j=0; i<t.size(); i++,j++,f[i]=j)
        while (j!=-1 && t[i]!=t[j]) j = f[j];
}
void kmp()
{
    for (int i=0,j=0; i<s.size(); i++,j++)
    {
        while (j!=-1 && s[i]!=t[j]) j=f[j];
        if (j==t.size()-1) cout << i-j+1 << '\n';
    }
}

int main()
{
    cin >> s >> t;
    build();
    kmp();
    for (int i=0; i<t.size(); i++)
        cout << f[i] << ' ';
    cout << '\n';
}