#include <iostream>
using namespace std;

int a[10][10];

int main()
{
    for (int i=1; i<=5; i++)
    {
        for (int j=1; j<=6; j++)
        {
            cin >> a[i][j];
        }
    }
    int flag=0;
    for (int i=1; i<=5; i++)
    {
        for (int j=1; j+2<=6; j++)
        {
            if (a[i][j] == a[i][j+1] && a[i][j] == a[i][j+2])
            {
                flag=1;
            }
        }
    }
    for (int i=1; i<=6; i++)
    {
        for (int j=1; j+2<=5; j++)
        {
            if (a[j][i] == a[j+1][i] && a[j][i] == a[j+2][i])
            {
                flag=1;
            }
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
}