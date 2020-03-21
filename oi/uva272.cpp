#include<iostream>
#include<algorithm>
using namespace std;

string s;
char q='`', q2='\'';
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (getline(cin,s))
    {
        int len=s.size();
        for( int i=0; i<len; i++)
        {
            if (s[i]=='\"')
            {
                cout << q << q;
                swap(q,q2);
            }
            else
            {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}