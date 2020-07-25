#include <bits/stdc++.h>
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

string s;
int n, f[50000010] = {-1};

int main()
{
    Eriri
    cin >> s, n = s.size();
    
    for (int i=1,j=0; i<n; i++,j++,f[i]=j)
        while (j!=-1 && s[i] != s[j]) j = f[j];

    if (f[n]>0 && n%(n - f[n])==0)
        cout << s.substr(0,n-f[n]) << '\n';
    else cout << s << '\n';
}