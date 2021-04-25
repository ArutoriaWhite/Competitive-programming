#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

struct REP
{
	char c; // if is end = E
	int x, y; // if x or y is n = 1e6
};

vector<REP> st;
int t, n;
int disa, curh, mxh, exi['z'+10];

inline int read_bigo()
{
	string s;
	cin >> s;
	if (s.size() == 4)
		return 0;

	int ans = 0;
	for (int i = 4; s[i]!=')'; i++)
		ans = ans*10 + s[i]-'0';
	return ans;
}
inline REP read_rep()
{
	string s, c, a, b;
	cin >> s;
	if (s[0] == 'F')
	{
		cin >> c >> a >> b;
		int x = (a[0]=='n'? 1e6:stoi(a));
		int y = (b[0]=='n'? 1e6:stoi(b));
		return {c[0], x, y}; 
	}
	else
		return {'E', 0, 0};
}
inline void init()
{
	st.clear();
	memset(exi,0,sizeof(exi));
	disa = 0;
	curh = 0;
	mxh = 0;
}

inline int wont_work (REP rep)
{
	return rep.x > rep.y;
}
inline int sol() //return -1 if ce, else return bigO = w^?
{
	int ce = 0;
	while (n--)
	{
		REP rep = read_rep();

		//de(rep.c), de(rep.x), de(rep.y), de(wont_work(rep)), dd;
//		continue;

		if (rep.c == 'E')
		{
			if (st.empty()) ce = 1;
			if (wont_work(st.back())) disa--;
			else if (st.back().y - st.back().x > 1000) curh--;
			if (!st.empty()) st.pop_back();
		}
		else
		{
			if (exi[rep.c]) ce = 1;
			exi[rep.c]++;
			st.pb(rep);
			if (wont_work(rep)) disa++;
			if (disa > 0) continue;
			if (rep.y - rep.x > 1000) curh++;
			mxh = max(mxh, curh);
		}
		//de(curh), de(mxh), dd;
	}
	if (!st.empty()) ce = 1;
	
	return (ce? -1:mxh);
}

inline void test()
{

}

signed main()
{
	test();
	pui
	cin >> t;
	while (t--)
	{
		init();
		cin >> n;
		int pred = read_bigo();
		int acut = sol();

//		de(pred), de(acut), dd;
		
		if (acut < 0)
			cout << "ERR\n";
		else
			cout << (pred==acut? "Yes":"No") << '\n';
	}
}

/*
4 O(n^2)
F x 9 n
E
F y 2 n
E
   */
