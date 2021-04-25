#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

vector<pii> B, S, e;
int n;

void add (pii &p1, pii &p2)
{
	if (p1.ss && p2.ss)
		e.pb({p1.ff, p2.ff}), p1.ss--, p2.ss--;	
}	

signed main()
{
	cin >> n;
	rep(i,1,n)
	{
		int p; cin >> p;
		if (p >= 2) B.pb({i,p});
		else S.pb({i,p});
	}
	if (B.empty())
		cout << (n==2? "YES 1\n1\n1 2\n":"NO\n");
	else
	{
		int dia = 0;
		for (int i=0; i+1<B.size(); i++) add(B[i],B[i+1]), dia++;
		if (S.size()>0) add(S[0],B[0]), dia++;
		if (S.size()>1) add(S[1],B.back()), dia++;

		while (S.size() && B.size())
		{
			while (S.size()&&S.back().ss==0) S.pop_back();
			while (B.size()&&B.back().ss==0) B.pop_back();
			if(S.size() && B.size()) add(S.back(),B.back());
		}
		if (S.empty())
		{
			cout << "YES " << dia << endl;
			cout << e.size() << endl;
			for (auto p: e) cout << p.ff << ' ' << p.ss << endl;
		}
		else cout << "NO\n";
	}
}
