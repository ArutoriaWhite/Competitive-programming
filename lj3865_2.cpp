#include <iostream>
using namespace std;
const int N = 1e5+10;

int st[30][N], k, n, m;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    n = read(), m = read();
    k = __lg(n);
    for (int i=0; i<n; i++) st[0][i] = read();
    for (int j=1; j<=k; j++)
        for (int i=0; i+(1<<j)<=n; i++)
            st[j][i] = max( st[j-1][i], st[j-1][i+(1<<(j-1))]);
    for (int i=0,j,l,r; i<m; i++)
    {
        cin >> l >> r;
        j = __lg(r-(l-1));
        cout << max( st[j][l-1], st[j][r-(1<<j)] ) << '\n';
    }
}