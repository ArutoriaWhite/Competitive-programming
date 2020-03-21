#include<iostream>
using namespace std;
#define maxN 100010

long long sum[maxN];
int n, s;

int main()
{
    while (cin >> n >> s)
    {
        for( int i=1; i<=n; i++)
        {
            int x;
            cin >> x;
            sum[i] = sum[i-1] + x;
        }
        int k=n-1;
        bool flag=0;
        for( int i=1; i<=n; i++)
        {
            for( int j=i+k; sum[j]-sum[i-1]>s&&k>0&&j<=n; j--,k--)
            {
                flag=1;
            }
        }
        if (flag) cout << k+2 << '\n';
        else cout << "0\n";
    }   
}