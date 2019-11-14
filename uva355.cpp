#include<iostream>
using namespace std;
#define ll long long

inline int ctoi( char c)
{
	if ('A'<=c&&c<='Z') return (c-'A'+10);
	else return (c-'0');
}

inline ll stoi( string s, int n)
{
	ll res = 0;
	for (int i=0; i<s.size(); i++,res+=ctoi(s[i]))
		res *= n;
	return res;
}

inline char itos( int x, int n)
{
	char s[100];
	int j;
	for (j=100; x>0; x/n)
	{
		s[--j] = x%n;
		x/n;
	}
	return &(s[j]+1);
}

int main() {
	int n, m;
	string s;
	while (cin >> m >> n >> s)
	{
		int k=2;
		for (int i=0; i<s.size(); i++)
			k = max(k,ctoi(s[i])+1);
		if (k>n || k>m)
			cout << s << " is an illegal base " << m << " number\n";
		else cout << 
	}
	return 0;
}
