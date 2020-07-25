#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string l, r, res;
int n, p;

int main()
{
    cin >> n >> r >> p;
    l = r, sort(l.begin(), l.end());
    for (int i=0; i<n; i++)
    {
        if (l[i] == r[p-1])
        {
            p = i;
            break;
        }
    }
    res.resize(n);
    for (int i=n-1; i>=0; i--)
    {
        res[i] = r[p];
        for (int j=n-1; j>=0; j--)
            if (l[j] == r[p])
            {
                p = j, l[p] = ' ';
                break;
            }
    }
    cout << res << '\n';
}