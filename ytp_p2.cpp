#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int k[10000], d[10000];

signed main(){
    int n, m, t, p=1, cont=1;
    cin >> n >> m >>t;
    int l = 0, r = n+1;
    for(int x=1;x<=n;x++){
        cin >> k[x];
    }
    for(int x=1; x<t;x++){
        cin >> d[x];
    }
    while(t--){
        p+=d[cont]+k[d[cont]+p];
        if (p >=r ){
            cout<< "Dumb Dumb Penguin\n";
            cout << "Survived " << cont << " rounds"<< '\n';
            break;
        }
        if (p == r-1)
        {
            cout << "Winner Penguin\n";
            cout << "Survived " << cont << " rounds"<< '\n';
            break;
        }
        l+=m;
        r-=m;

          if(r-l<=1){
            cout << "Dumb Dumb Penguin\n";
            cout << "Survived " << cont << " rounds"<< '\n';
            break;
        }
        if(p == r-1){
            cout << "Winner Penguin\n";
            cout << "Survived " << cont << " rounds"<< '\n';
            break;
        }
        if(p<=l||p>=r){
             cout<< "Dumb Dumb Penguin\n";
             cout << "Survived " << cont << " rounds"<< '\n';
            break;
        }
        cont++;
    
    }
}