#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

int t, rx, ry, k, T;

int ask (int x, int y)
{
	cout << 0 << ' ' << x << ' ' << y << endl;	
	int res;
	cin >> res;
	return res;
}
void answer (int x, int y)
{
	cout << 1 << ' ' << x << ' ' << y << endl;
}
int rbound()
{
	int i=0, s=2*t;
	while (s)
	{
		if (ask(rx+i+s,ry))
			i += s;
		else 
			s>>=1;
	}
	return rx+i;
}
int lbound()
{
	int i=0, s=-2*t;
	while (s)
	{
		if (ask(rx-i-s,ry))
			i += s;
		else 
			s >>=1;
	}
	return rx-i;
}
int upbound()
{
	int i=0,s=2*t;
	while (s)
	{
		if (ask(rx,ry+i+s))
			i += s;
		else
			s >>= 1;
	}
	return ry+i;
}
int lwbound()
{
	int i=0,s=2*t;
	while (s)
	{
		if(ask(rx,ry-(i+s)))
			i += s;
		else 
			s >>= 1;
	}
	return ry-i;
}

signed main()
{
	cin >> T;
	while (T--)
	{
		cin >> t >> rx >> ry >> k;
		int rb = rbound();
		int lb = lbound();
		int upb = upbound();
		int lwb = lwbound();	
		answer((rb+lb)/2,(upb+lwb)/2);
	}
}
