#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
/*
x and y adj if (x*y/gcd(x,y)/gcd(x,y) = k^2)

after a second for all i, a[i] = product of a[j] that a[j] adj with a[i]

then have q queries w, answer after w second, the max number that someone has adj in the array
*/