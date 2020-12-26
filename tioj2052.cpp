#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 1500;

int cnt[200], m, c[N][N], n;
string s;

inline int calc ()
{
	int x=0, res=1;
	for (int i=0; i<200; i++) x += cnt[i];
	for (int i=0; i<200; x-=cnt[i],i++)
		res = (res*c[x][cnt[i]])%m;
	return res;
}   

signed main()
{
	shaaark
	cin >> m >> s;
	n = SZ(s);
	rep(i,0,n) c[i][0] = 1;
	rep(i,1,n) rep(j,1,n) c[i][j]=(c[i-1][j-1]+c[i-1][j])%m;
	rep(i,0,n-1) cnt[s[i]]++;
	int res=0;
	for (int i=0; i<n; i++)
	{
		for (char j='a'; j<='z'&&j<s[i]; j++)
			if(cnt[j]>0) cnt[j]--, res = (res+calc())%m, cnt[j]++;
		for (char j='A'; j<='Z'&&j<s[i]; j++)
			if(cnt[j]>0) cnt[j]--, res = (res+calc())%m, cnt[j]++;
		cnt[s[i]]--;
	}
	cout << res << '\n';
}