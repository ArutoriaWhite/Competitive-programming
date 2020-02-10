#include <bits/stdc++.h>
using namespace std;
const int N = 25;

string kw[N], exu[N];
int ans[N], maxv, k, e, r, fir=1, t;

inline char lower_case (const char &c)
{
	return ('a'<=c&&c<='z')? (c) : (c-'A'+'a');
}

inline int count (const string &ex, const string &ky)
{
	string s = "";
	int res = 0;
	for (int i=0,len=ex.size(); i<len; i++)
	{
		if (('a'<=ex[i]&&ex[i]<='z') || ('A'<=ex[i]&&ex[i]<='Z'))
			s += lower_case(ex[i]);
		else
		{
			if (s == ky) res++;
			s = "";
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> k >> e)
	{
		r=0, maxv=0;
		for (int i=0; i<k; i++)
			cin >> kw[i];
		cin.ignore();
		for (int i=0; i<e; i++)
			getline(cin,exu[i]);

		for (int i=0,cnt; i<e; i++)
		{
			cnt=0;
			for (int j=0; j<k; j++)
				cnt += count(exu[i],kw[j]);
			if (cnt > maxv)
				ans[r=0] = i, maxv = cnt, r++;
			else if (cnt == maxv)
				ans[r++] = i;
		}

		cout << "Excuse Set #" << ++t <<"\n";
		for (int i=0; i<r; i++)
			cout << exu[ans[i]] << "\n";
		cout << "\n";
	}
}
