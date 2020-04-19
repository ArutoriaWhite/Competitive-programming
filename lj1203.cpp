#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define MegumiMyWife ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 400;

char c[N], co;
int n, res;

int main ()
{
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> c[i];
    for (int i=0,j; i<n; i++)
    {
        for (j=1; j<n; j++)
        {
            if (c[(i+j)%n] != c[i] && c[(i+j)%n]=='w')
        }
        res = max(res, j+1);
    }
    cout << res << '\n';
}