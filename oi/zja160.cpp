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
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 15;

int xpos[N], cnt, fir=1, n;

void print (int y, int down, int l, int r)
{
	if (y==n)
	{
		cnt++;
		if (fir) fir=0;
		else cout << '\n';
		for (int y=0; y<n; y++)
		{
			for (int x=0; x<n; x++)
				cout << (x==xpos[y]? 'Q':'x');
			cout << '\n';
		}
	}
	for (int x=0; x<n; x++)
		if (!(down&(1<<x) || l&(1<<x) || r&(1<<x)))
		{
			xpos[y] = x;
			print(y+1,down|(1<<x),(l|(1<<x))<<1,(r|(1<<x))>>1);
		}
}

int main()
{
	akiyama;
	while (cin >> n && n)
	{
		cnt = 0;
		print(0,0,0,0);
		
		cout << '\n' << cnt << '\n';
	}
}
