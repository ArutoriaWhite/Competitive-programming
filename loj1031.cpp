#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 1e2;

int owo[N], n, avr, res;

int main()
{
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> owo[i], avr+=owo[i];
	avr /= n;
	for (int sum=0,i=0; i<n; i++)
	{
		sum = sum+owo[i]-avr;
		if (sum!=0) res++;
	}
	cout << res << '\n';
}
