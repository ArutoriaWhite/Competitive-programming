#include <iostream>
using namespace std;

int Max_x=-1e9, n;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        Max_x = max(Max_x, x);
    }
    cout << Max_x << '\n';
}
