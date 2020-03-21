#include <iostream>
#define DE cout << " ::"
using namespace std;

string s, ouo;
int n, nouo, r;

inline bool all_a()
{
	for (int i=0; i<n; i++)
		if (s[i]!='a') return 0;
	return 1;
}

inline void gen_ouo()
{
	for (int i=0; i<n; i++)
		if (s[i]!='a')
			ouo += s[i];
	nouo = ouo.size();
}

inline int bef_a()
{
	int res=0, tmp=0;
	for (int i=0; i<n; i++)
		if (s[i]=='a') res = tmp;
		else tmp++;
	return res;
}

inline int check()
{
	for (int i=0,j=(nouo)/2; j<nouo; i++,j++)
		if (ouo[i]!=ouo[j]) return 0;
	return 1;
}

int main()
{
	cin >> s;
	n = s.size();
	if (all_a())
	{
		cout << s << '\n';
		return 0;
	}
	gen_ouo();
	
	if (bef_a()>(nouo>>1) || nouo&1 || (!check())) cout << ":(\n";
	else
	{
		int i, r;
		for (i=0,r=0; i<(nouo)/2; i+=(s[r]!='a'),r++) cout << s[r];
		while (s[r]=='a') cout << s[r++];
		cout << '\n';
	}
}
