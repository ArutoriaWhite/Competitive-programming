#include<iostream>
using namespace std;

int main()
{
    string s;
    while (getline(cin,s))
    {
        for( int len=s.size(),i=0; i<len; i++)
        {
            cout << (char)(s[i]-7);
        }
	cout << '\n';
    }   
}
