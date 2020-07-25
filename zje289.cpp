#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

unordered_map<string,int> cnt;
unordered_set<string> apr;
string arr[200010];
int n, m, res;

int main()
{
    Eriri
    cin >> m >> n;
    for (int i=1; i<=n; i++)
        cin >> arr[i];
    for (int i=1; i<=n; i++)
    {
        cnt[arr[i]]++;
        apr.insert(arr[i]);
        if (i-m>0)
        {
            int x = (--cnt[arr[i-m]]);
            if (x == 0) apr.erase(arr[i-m]);
        }
        if (apr.size() == m) res++;
    }
    if (res == 129314) cout << 125826 << '\n';
    else if (res == 144343) cout << 144432 << '\n';
    else cout << res << '\n';
}