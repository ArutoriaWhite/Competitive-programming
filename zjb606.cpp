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
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0;
const int N = 5e3+10;

int n;

namespace Heap
{
	int hp[N<<1], r;
	inline void init()
	{
		mem(hp,INF);
		r = 0;
	}
	inline void push (int x)
	{
		hp[++r] = x;
		for (int i=r; i>1 && hp[i>>1]>x; swap(hp[i>>1],hp[i]),i>>=1);
	}
	inline int size()
	{
		return r;
	}
	inline int pop()
	{
		int res = hp[1], i;
		for (i=1,hp[1]=hp[r--]; (i<<1)<=r; )
		{
			int j = (hp[i<<1]<hp[i<<1|1]? (i<<1) : (i<<1|1));
			if (hp[i]>hp[j]) swap(hp[i], hp[j]), i = j;
			else break;
		}
		return res;
	}
}

int main()
{
	while (cin >> n && n)
	{
		int res = 0, x=0;
		Heap::init();
		for (int i=0,x; i<n; i++)
			cin >> x, Heap::push(x);
		while (Heap::size()>1)
			x = Heap::pop() + Heap::pop(), Heap::push(x), res+=x;
		cout << res << '\n';
	}
}

