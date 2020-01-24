#include <iostream>
using namespace std;
const int N = 15;

int num[N], sol[N], n;

inline void f (int i, int s)
{
    if (s==6)
    {
        for (int i=0; i<s; i++)
            cout << sol[i] << ' ';
        cout << '\n';
        return;
    }
    sol[s] = num[i], f(i+1,s+1);
    if (n-i > 6-s) f(i+1,s);
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
        f(0,0);
    }
}
/*
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0
*/