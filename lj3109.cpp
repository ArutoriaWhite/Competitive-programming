#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;
struct Player
{
	int id, weight, score;
} players[N];

inline int redn() {
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

inline int cmp (Player i, Player j)
{
	if (i.score != j.score)
		return i.score > j.score;
	return i.id < j.id;
}

int n, r, q;

signed main()
{
	pui
	n = redn(), r = redn(), q = redn();
	n *= 2;
	rep(i,1,n)
		players[i].id = i;
	rep(i,1,n)
		players[i].score = redn();
	rep(i,1,n)
		players[i].weight = redn();

	sort(players+1,players+1+n,cmp);
	while (r--)
	{
		vector<Player> win, los;
		for (int i=1; i<=n; i+=2)
		{
			if (players[i].weight > players[i+1].weight)
				players[i].score++, win.pb(players[i]), los.pb(players[i+1]);
			else
				players[i+1].score++, win.pb(players[i+1]), los.pb(players[i]);
		}
		merge(win.begin(), win.end(), los.begin(), los.end(), players+1, cmp);
	}	
	cout << players[q].id << '\n';
}
