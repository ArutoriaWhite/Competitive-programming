#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

map<string,int> pool;
struct Unit
{
	string id;
	int value = 0;
	int get()
	{
		if (pool.find(id) != pool.end())
			return pool[id];
		return value;
	}
	Unit (string s)
	{
		if (s.size() == 0) return;
		else if ('0'<=s[0] && s[0]<='9')
			for (int i=0; i<s.size(); i++)
				value = value*10 + s[i]-'0';
		else 
		{
			id = s;
			if (pool.find(id) == pool.end())
				pool[id] = 0;
		}
	}
};

vector<Unit> read()
{
	string s;
	cin >> s;
	s.pop_back();
		
	vector<Unit> ans;
	vector<string> splits;

	int i = 0;
	splits.pb("");
	for (; s[i]!='='; i++)
		splits.back().pb(s[i]);

	splits.pb("");
	for (i++; i<s.size()&&s[i]!='+'; i++)
		splits.back().pb(s[i]);

	splits.pb("");
	for (i++; i<s.size()&&s[i]!=';'; i++)
		splits.back().pb(s[i]);

	rep(j,0,2)
		ans.pb(Unit{splits[j]});
	
	return ans;
}

signed main()
{
	pui
	int n; cin >> n;
	while (n--)
	{
		vector<Unit> units = read();
		pool[units[0].id] = units[1].get() + units[2].get(); 
	}
	for (auto kvp: pool)
	{
		cout << kvp.ff << ' ' << kvp.ss << '\n';
	}
}

