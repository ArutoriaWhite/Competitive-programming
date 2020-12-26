#include <iostream>
using namespace std;

signed main()
{
    int n;
    while (cin >> n)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j+i<=n; j++)
            {
                cout << ' ';
            }
            for (int j=1; j<=i; j++)
            {
                cout << (char)('A'+j-1);
            }
            cout << '\n';
        }
        for (int i=1; i<n; i++)
        {
            for (int j=1; j<=i; j++) 
            {
                cout << ' ';
            }
            for (int j=1; j+i<=n; j++)
            {
                cout << (char)('A'+j-1);
            }
            cout << '\n';
        }
    }
}