#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define exi(x,s) (s.find(x)!=s.end())
#define fi first
#define se second
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0;
const int N = 110;

int arr[N];

inline void isp (int x)
{
	for (int i=30; i<40; i++)
	{
		if (qpow(i,x-1,x)!=1)
			return 0;
	}
	return 1;
}
