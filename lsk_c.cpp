#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n,m;
int z,k,ans,best;
char c;

int l()
{
    return sqrt(pow((double)L.x-(double)S.x,2)+pow((double)L.y-(double)S.y,2));
}

signed main(){
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            char c;
            cin >> c;
            if (c=='L')
            {
                L.y = i;
                L.x = j;
            }
            else if (c=='S')
            {
                S.y = i;
                S.x = j;
            }
        }
    }
    cin>>z;
    best=l();
    for (int i=1; i<=z; i++)
    {
        cin >> c >> k;
        if (c=='x') S.x += k;
        if (c'y') S.y -= k;
        S.y = (S.y+n)%n;
        S.x = (S.x+m)%m;
        if (l()<best)
        {
            best = l();
            ans = i;
        }
    }
    cout<<ans<<endl;
    return 0;
}