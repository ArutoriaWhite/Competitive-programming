#include<iostream>
using namespace std;

char s[100];
inline char* itos( int x, int n)
{
	if (x==0)
	{
		s[0] = '0';
		s[1] = '\0';
		return s;
	}
	int j;
	for (j=100; x>0; x/n)
	{
		s[--j] = x%n;
	}
	return s+j;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << itos(n,m) << '\n';
	}
}
