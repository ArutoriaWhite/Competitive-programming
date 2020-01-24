#include <iostream>
using namespace std;
const int N = 15;

int num[N], n;

void dfs (int i, int d)
{
    if (d==6)
    {
        cout << '\n';
        return;
    }
    for (int j=i; j<n&&j<n-(6-d-1); j++)
        cout << num[j] << ' ', dfs(i+1,d+1);
}

int main()
{
    while (cin >> n)
    {
        for (int i=0; i<n; i++)
            cin >> num[i];
        dfs(0,0);
    }
}