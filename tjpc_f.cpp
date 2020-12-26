#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string a, b;
int x, n;

int main()
{
    cin >> n >> a >> b;
    for (int i=0; i<n; i++)
        x += a[i]!=b[i];
    cout << max(0, x-2) << '\n';
}