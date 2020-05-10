#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int n, k, t;
string s;

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        if (s[0]==s[k-1] && s[k]==s[n-1])
        {
            cout << s[0];
            for (int i=0; i<((n-k)/k)+((n-k)%k>0); i++)
                cout << s[k];
        }
        else if (s[0]==s[k-1] && s[k]!=s[n-1])
        {
            cout << s[0];
            for (int i=k; i<n; i++)
                cout << s[i];
        }
        else
            cout << s[k-1];
        cout << '\n';
    }
}