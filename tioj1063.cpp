#include<bits/stdc++.h>
using namespace std;
bool gr[205][205];
int n,m,r[205],ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>gr[i][j];
            gr[i][j]?r[j]++:r[j]=0;
            for(int k=j, s=r[j]; k>=0 && r[k]>=s; k--) {
                ans=max(ans,s*(j-k+1));
                s=min(s,r[k]);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}