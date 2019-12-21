#include<iostream>
#include<cstring>
using namespace std;

int ouo[300], rem[300];

inline void print (char c, int n)
{
    for (int i=0; i<n; i++)
        cout << c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        memset(ouo,0,sizeof(ouo));
        memset(rem,0,sizeof(rem));

        string s;
        cin >> s;
        for (int i=0; i<s.size(); i++)
        {
            ouo[ s[i] ]++;
        }

        int ver = min(ouo['D'],ouo['U']);
        int hor = min(ouo['L'],ouo['R']);

        if (ver == hor && hor == 0)
        {
            cout << "0\n";
        }
        else if (ver == 0)
        {
            cout << "2\n";
            cout << "LR\n";
        }
        else if (hor == 0)
        {
            cout << "2\n";
            cout << "UD\n";
        }
        else
        {
            cout << ((ver+hor)<<1) << '\n';
            print('U',ver);
            print('R',hor);
            print('D',ver);
            print('L',hor);
            cout << '\n';
        }

    }
}