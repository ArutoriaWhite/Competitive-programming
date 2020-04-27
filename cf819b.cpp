#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N =1e6+10;

int arr[N], n, gre[N];

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> arr[i];
    for (int i=1; i<=n; i++)
    {
        gre[ max( arr[i]-i, 0) ]++;2
    }
}