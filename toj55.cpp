#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

int arr[N], n, m;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr,arr+n);

    cin >> m;
    for (int i=0,x; i<m; i++)
    {
        cin >> x;
        cout << upper_bound(arr,arr+n,x) - lower_bound(arr,arr+n,x) << '\n';
    }
}