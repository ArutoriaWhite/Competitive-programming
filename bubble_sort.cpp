#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e3+10;

int a[N], n;

int main()
{
    Eriri
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=n; i>0; i--)
        for (int j=i; j<n&&a[j]>a[j+1]; j++)
            swap(a[j], a[j+1]);
    for (int i=1; i<=n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}