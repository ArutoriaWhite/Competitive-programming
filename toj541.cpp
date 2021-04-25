#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define endl '\n'
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

string A, C, S, ans;

signed main()
{
	cin >> S >> A;
	int k = (S.size());
	for (int i=0; i<A.size(); i+=10)
	{
		string tmp;
		int x = 0;
		for (int j=0; j<10; j++)
			x = x*10LL + A[i+j]-'0';
		for (int j=0; j<32; j++,x>>=1)
			tmp += "01"[x&1];
		reverse(tmp.begin(), tmp.end()), C += tmp;
	}
	int f = 0;
	while (f<C.size() && C[f] == '0') f++; // first index not 0
	int x = 0;
	for (int i=C.size()-1,t=1; i>=f; i--,t=t*2%(k+1))
	{
		x = x+(C[i]=='1')*t;
		if (x >= (k+1))
			ans += (x%(k+1)? S[x%(k+1)-1]:'\n');
		x %= (k+1);
	}
	if (x > 0) ans += S[x];
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
/*
dmohT2y_Wxi1M0ulvqnDZ-sg7eK9Yab
011061433207045509153920580726148361011704574725262013754683395647563703657618312810451232

   */
