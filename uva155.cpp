#include<iostream>
#include<iomanip>
using namespace std;

int ans;
void dfs ( int x, int y, int s, int qx, int qy)
{
	if (s==0) return;
	int u=y-s, d=y+s, l=x-s, r=x+s;
	if ((u<=qy&&qy<=d) && (l<=qx&&qx<=r))
		ans++;
	dfs(x+s,y+s,s>>1,qx,qy);
	dfs(x+s,y-s,s>>1,qx,qy);
	dfs(x-s,y-s,s>>1,qx,qy);
	dfs(x-s,y+s,s>>1,qx,qy);
}

int main()
{
	int k, qx, qy;
	while (cin >> k >> qx >> qy)
	{
		if (k==0 && qx==0 && qy==0) break;
		ans = 0;
		dfs(1024,1024,k,qx,qy);
		cout << setw(3) << ans << '\n';
	}
}
