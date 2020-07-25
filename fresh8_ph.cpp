#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int t, n;

int sol (int l, int r, int sta)
{
    int k = (r-l+1)/3
    Pii A = {l,l+k-1}, B = {l+k,l+2*k-1}, C = {l+2*k,l+3*k-1}, D = {l+3*k,r}, Cp = {l,l+(r-l)%k-1};
    if (sta == 0)
    {
        int x = ask(A,B), y = ask(B,C);
        if (x == -1)
        {
            if (y==0) return sol(A.F,A.S,110);
            if (y==1) return sol(B.F,B.S,90);
        }
        if (x == 0)
        {
            if (y==-1) return sol(C.F,C.S,90);
            if (y==0)
            {

            }
        }
        if (x == 1)
        {

        }
    }
    if (sta == 90)
    {

    }
    if (sta == 110)
    {

    }
    if (sta == 100)
    {
        
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << sol(1,n) << '\n';
    }
}