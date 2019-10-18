#include<iostream>
using namespace std;

string s;
int len, sum, cnt;
int table[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    table['W'] = 64;
    table['H'] = 32;
    table['Q'] = 16;
    table['E'] = 8;
    table['S'] = 4;
    table['T'] = 2;
    table['X'] = 1;

    while (getline(cin,s))
    {
        if (s=="*") break;

        len=s.size();
        sum=0, cnt=0;

        for( int i=1; i<len; i++)
        {
            if (s[i]=='/')
            {
                if (sum==64)
                {
                    cnt++;
                }
                sum=0;
                continue;
            }
            sum += table[s[i]];
        }
        cout << cnt << '\n';        
    }
}