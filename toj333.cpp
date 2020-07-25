#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

long long q, s, qiao, shang, a;

int main ()
{
    Eriri
    int n;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        if (i == 1)
            qiao = 0, shang = a;
        else
        {
            q = max( qiao, shang-a);
            s = max( shang, qiao+a);
            qiao = q, shang = s;
        }
    }
    cout << shang << '\n';
}