#include <iostream>
using namespace std;
const int N =15;

int num[N], sol[N], n;

void dfs (int i, int d)
{
    if (d==6)
    {
        for (int i=0; i<6; i++)
            cout << sol[i] << " \n"[i+1>=6];
        return;
    }
    for (int j=i; j<n&&j+(5-d)<n; j++)
    {
        sol[d] = num[j];
        dfs(j+1,d+1);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    bool fir=1;
    while (cin >> n && n!=0)
    {
        if (fir) fir=0;
        else cout << '\n';
        for (int i=0; i<n; i++)
            cin >> num[i];
        dfs(0,0);
    }
}  