#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int P = 19260817;

int a, b;

inline int qpow (int i, int j)
{
	int res = 1;
	for (; j; j>>=1,i=i*i%P)
		if (j&1) res = res*i%P;
	return res;
}
inline void read (int &res)
{
	string s; cin >> s;
	for (int i=0; i<s.size(); i++)
		res = (res*10%P + s[i]-'0')%P;
}

signed main()
{
	read(a), read(b);
	cout << a*qpow(b,P-2)%P << endl;
}
