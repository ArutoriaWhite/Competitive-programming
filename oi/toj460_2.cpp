#include<bits/stdc++.h>
using namespace std;
#define DOM 4
#define N 0
#define W 1
#define E 2
#define S 3

int G[5][5][5], sco[2];
pair<int,int> ord[9];

inline int hex (char c)
{
	if ('0'<=c && c<= '9')
		return c-'0';
	return (c-'A'+10);
}

int main()
{
	memset(G,0x3f,sizeof(G));
	for (int i=1; i<=3; i++)
	{
		for (int j=1; j<=3; j++)
			ord[getchar()-'0'] = {j,i};
		getchar();
	}
	
	for (int i=0; i<9; i++)
	{
		int x = ord[i].first, y = ord[i].second;
		int *cur = G[x][y];
		cur[DOM] = i&1, sco[i&1]++;
		for (int curF=0; curF<4; curF++)
		{
			cur[curF] = hex(getchar());
			int *adj, adjF;
			if 		(curF==N) adj = G[x][y-1], adjF = S;
			else if (curF==W) adj = G[x-1][y], adjF = E;
			else if (curF==E) adj = G[x+1][y], adjF = W;
			else if (curF==S) adj = G[x][y+1], adjF = N;
			
			if ((adj[DOM]^cur[DOM]) && adj[adjF]<=cur[curF])
				adj[DOM] = cur[DOM], sco[i&1]++, sco[!(i&1)]--;
		}
		getchar();
	}
	printf("%d-%d\n",sco[0],sco[1]);
}
