#include <iostream>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back()
#define pui ios::sync_with_stdio(), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int D = 1e9+7;

inline int redn() {
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

inline int qpow (int i, int j)
{
	int res = 1;
	for (; j; j>>=1)
	{
		if (j&1)
		{
			res = res*i;
			if (res>=D) res %= D;
		}
		i *= i;
		if (i >= D) i %= D;
	}
	return res;
}

int T, a, b, h;

signed main()
{
	pui
	T = redn();
	while (T--)
	{
		a = redn(), b = redn(), h = redn();
		if (b == 1) cout << ((a-1)*h+a)%D << '\n';
		else
		{
			int p = qpow(b,h)*a%D;
			int q = (a-b)*(qpow(b,h)-1)%D*qpow(b-1,D-2)%D;
			if (b > a) cout << p << '\n';
			else if (b < a) cout << (p+q)%D << '\n';
			else cout << p << '\n';
		}
	}
}
