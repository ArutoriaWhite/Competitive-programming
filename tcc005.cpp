#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

char c[200];

signed main()
{
	ShinraTensei
	c['A'] = 'U';
	c['T'] = 'A';
	c['G'] = 'C';
	c['C'] = 'G';
	char ch;
	while (cin >> ch) cout << c[ch];
}

