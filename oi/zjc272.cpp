#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 15, M = 1e7;

int n, m, q, owo[N], val[M], r;

inline int calc()
{
	int res = 0;
	for (int i=0; i<n; i++)
		res += owo[i]*(m-min(i,m+1)+1);
	return res;
}

int main()
{
	akiyama;
	cin >> n >> m >> q;
	for (int i=0; i<n; i++)
		cin >> owo[i];
	sort(owo,owo+n);

	do val[r++] = calc();	
	while (next_permutation(owo,owo+n));
	sort(val,val+r);
	

	for (int t=1,x; t<=q; t++)
	{
		cout << "Case #" << t << "\n";
		cin >> x;
		if (val[0] > x)
			cout << "No Solution!\n";
		else
			cout << *(upper_bound(val,val+r,x)-1) << '\n';
	}
}
