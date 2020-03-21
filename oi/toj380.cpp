#include<bits/stdc++.h>
using namespace std;
#define rep( i, a, b) for( int i =(a); i<(b); i++)
#define ll long long

#define local 
#define IMP -1

int amnt[5][1024];
ll dp[5][1024];

ll f( int c, int hasAtk){
	ll ans = dp[c][hasAtk];
	if( ans == IMP){
		ans = 0;
		if( c==0) ans = ( hasAtk == 1023);
		else rep( addAtk, 0, 1024){
			ans += f( c-1, addAtk|hasAtk)*amnt[c-1][addAtk];
		}
	}
	return ans;
}

int main(){
#ifdef local
	freopen( "in.txt", "r", stdin);
#else
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	memset( dp, IMP, sizeof( dp));
		
	int n; cin >> n;
	rep( _t, 0, n){
		int c; cin >> c;
		int hasAtk = 0;
		rep( shift, 0, 10){
			int _atk; cin >> _atk;
			hasAtk += _atk<<shift;
		}
		amnt[c-1][hasAtk]++;
	}
		
	cout << f( 5, 0) << '\n';
}
