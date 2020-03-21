#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int ouo[3];
        for (int i=0; i<3; i++)
            cin >> ouo[i];
        sort(ouo,ouo+3);
        cout << (max(ouo[2]-ouo[0]-2,0)*2) << '\n';
    }
}