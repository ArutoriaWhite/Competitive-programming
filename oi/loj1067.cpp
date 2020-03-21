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
const int INF=0x7f7f7f7f, N = 110;

int owo[N], n;

int main()
{
	akiyama;
	cin >> n;
	for (int i=0; i<n+1; i++)
		cin >> owo[i];
	for (int i=0; i<n+1; i++)
	{
		if (owo[i] == 0) continue;

		if (i>0 && owo[i]>0) cout << '+';
		else if (owo[i]<0) cout << '-';

		if (abs(owo[i])>1 || i==n) cout << abs(owo[i]);

		if (i<n-1) cout << "x^" << n-i;
		else if (i==n-1) cout << "x";
	}
	cout << '\n';
}
