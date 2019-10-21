#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
#define maxN 10000

string s[maxN];
bool time[31];
int main()
{
    freopen("in.txt","r",stdin);
    
    int n;
    cin >> n;
    for( int i=0; i<n; i++)
    {
        cin >> s[i];
    }

    sort(s,s+n);
    int m=0x3f3f3f3f;
    string ms;
    for( int i=0; i<n; i++)
    {
        memset( time, 0, sizeof(time));
        string &k = s[i];

        for( int j=0; j<n; j++)
        {
            time[k[j]%31]=1;
        }
        int sum=0;
        for( int j='A'; j<='Z'; j++)
        {
            sum+=time[j%31];
        }

        if (sum<m)
        {
            m=sum;
            ms=k;
        }
    }
    cout << ms << '\n';
}