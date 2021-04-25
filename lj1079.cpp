#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

signed main()
{
	string key, cry;
	cin >> key >> cry;
	for (int i=0,j=0,t=0; t<max(SZ(key), SZ(cry)); i=(i+1)%SZ(key),j=(j+1)%SZ(cry),t++)
	{
		char k = key[i], c=cry[j];
		int isu=0;
		if ('A'<=k && k<='Z') k += -'A'+'a';
		if ('A'<=c && c<='Z') c += -'A'+'a', isu=1;
		int x = ((c-'a') - (k-'a') + 26 )%26;
		cout << (char)((isu? 'A':'a')+x);
	}
	cout << '\n';
}
