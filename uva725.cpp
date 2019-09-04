#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for( int i=(a); i<(b); i++)

int amnt[10], n1 = 0, tar_n =0;

int bt( int n){
    if( n == 5){

    }
    rep( add_n, 0, b){
        if( amnt[add_n] <= 0) continue;
        int shifted =add_n;
        rep( i, 0, n){ shifted*=10;}

        n1+= shifted;
        amnt[add_n] = 0;
        bt( n+1);
        n1 -= shifted;
    }

}

int main(){
    while( cin >> n){
        if( n == 0) break;

    }
    return 0;
}
