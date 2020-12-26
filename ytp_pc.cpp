#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
long long n;
vector<int>v;
int  main(){
    scanf("%d",&n);
    for(int i=1,j;i<=n;i++){
        for(j=1;j<=i;j++);
        v.push_back(i+j);
    }
}