#include <bits/stdc++.h>
using namespace std;

int n, a[1010];

int main()
{
    cin >> n;
    a[1] = 1;
    for (int k=1; k<=n; k++)
    {
        for (int i=k; i>=1; i--) a[i] = a[i]+a[i-1];
        for (int i=0; i<n-k; i++) cout << ' ';
        for (int i=1; i<=k; i++) cout << a[i] << ' ';
        cout << '\n';
    }
}