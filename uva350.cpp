#include<iostream>
using namespace std;
#define maxM 10010

int z,i,m,l,cnt;
int used[maxM], u=0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (cin >> z >> i >> m >> l)
    {
        if (z==i && i==m && m==l && l==0) break;
        cout << "Case " << ++u;
        for( cnt=0; used[l]<u; used[l]=u,l=((z*l+i)%m),cnt++);
        cout << ": " << cnt << '\n';
    }
}