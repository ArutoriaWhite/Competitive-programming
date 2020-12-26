#include <iostream>
using namespace std;
const int N = 2e5+10;

int arr[N], n, q;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cin >> q;
    int flag=0;
    for (int i=1; i<=q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (abs(a-b)>8)
        {
            flag=1;
            break;
        }
        swap(arr[a], arr[b]);
    }
    if (flag) cout << "I QUIT!\n";
    else cout << "SORTED!\n";
    for (int i=1; i<=n; i++)
        cout << arr[i] << "\n "[i+1<=n];
}