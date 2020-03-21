#include<iostream>
using namespace std;
#define DE cout << " ::"

int n;
bool exi;
void dfs (long long x, int d, long long ap)
{
    if (d==0)
    {
        long long y=x*n, tmp=y;
        bool flag=1;
        while (tmp>0)
        {
            if (ap&(1<<tmp%10)) flag=0;
            ap|=(1<<tmp%10), tmp/=10;
        }
        if (flag && ap+1 == (1<<10))
        {
            cout << y << " / ";
            if (x<10000) cout << "0";
            cout << x << " = " << n << "\n";
            exi=1;
        }
            
    }
    else
    {
        for (int i=0; i<10; i++)
            if ((ap&(1<<i))==0)
                dfs(x*10+i,d-1,ap|(1<<i));        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool fir=1;
    
    while (cin >> n)
    {
        exi=0;
        if (n==0) return 0;
        if (fir) fir=0;
        else cout << '\n';
        
        dfs(0,5,0);
        if (!exi) cout << "There are no solutions for " << n << ".\n";
    }
}