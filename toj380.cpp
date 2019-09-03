#include <bits/stdc++.h>
using namespace std;
#define rep( i, a, b) for( int i =(a); i<(b); i++)
#define ll long long

#define IMP -1
#define local

ll dparr[5][1024];
int amnt[5][1024];

ll dp( int c, int atk){
    ll &u = dparr[c][atk];
    if( u == IMP){
        u = 0;
        if( c == 0){
            if( atk == 1023) u = 1;
            else u = 0;
        }
        else rep( v_atk, 0, 1024){
            u = ( dp( c-1, v_atk) +u);
        }
        u =( amnt[c][atk] * u);
    }
    return u;
}

int main(){
#ifdef local
    freopen( "in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif // local
    memset( dparr, IMP, sizeof( dparr));
    int n; cin >> n;
    rep( i, 0, n){
        int c; cin >> c;
        int atk_key = 0;
        rep( shift, 0, 10){
            int _atk; cin >> _atk;
            atk_key += _atk << shift;
        }
        amnt[c-1][atk_key]++;
    }
    cout <<  dp( 4, 0) << '\n';
}
