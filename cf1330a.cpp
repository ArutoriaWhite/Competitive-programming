#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int arr[110], T, res, n, x, j;

int main()
{
    Eriri
    cin >> T;
    while (T--)
    {
        cin >> n >> x;
        for (int i=0; i<n; i++)
            cin >> arr[i];
        sort(arr,arr+n), n=unique(arr,arr+n)-arr;
        for (res=1,j=0; res<=300; res++)
        {
            if (j<n&&arr[j]==res) j++;
            else if (x>0) x--;
            else break;
        }
        cout << res-1 << '\n';
    }
}