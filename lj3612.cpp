#include <bits/stdc++.h>
#define int __int128
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

string s;
int n, q;

int red()
{
	long long x;
	cin >> x;
	return x;
}

signed main()
{
	cin >> s;
   	q = red();
	n = s.size();
	q--;

	int tmpq = q;
	
	int k = n;
	while (k <= q) k *= 2;
	
	while (q >= n)
	{
		while (k>q && q>=n) k/=2;
		q = (q-1+k)%(k);
	}
	
	cout << s[q] << '\n';
}
