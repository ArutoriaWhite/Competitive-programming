#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb emplace_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 1e6+10;

unsigned long long res, M = 1;
int n, a[N], b[N];

int main()
{
	for (int i=0; i<64; i++) M *= 2;
	de(M), dend;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	sort(a,a+n);
	for (int i=0; i<n; i++)
		res = (i+a[0] - a[i] + res)%M;
	cout << (res*b[0])%M << '\n';
}

