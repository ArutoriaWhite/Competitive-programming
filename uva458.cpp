#include<iostream>
using namespace std;
#define K -7

string s;

int main()
{
    while (getline(cin,s))
    {
        int len = s.size();
        for( int i=0; i<len; i++)
        {
            cout << (char)(s[i]+K);
        }
        cout << '\n';        
    }
}