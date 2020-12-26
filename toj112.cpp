#include <iostream>
using namespace std;

int a[20], n;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for (int i=n; i>0; i--)
    {
        cout << a[i] << '\n';
    }
}