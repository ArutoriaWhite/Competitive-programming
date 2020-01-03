#include<iostream>
using namespace std;
const int N=1e2+10;

string G[N];
int tow[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	bool fir=1;
	int n, m, t=0;
	while (cin >> n >> m)
	{
		if (n==0 && m==0) break;
		if (fir) fir=0;
		else cout << '\n';
		
		cout << "Field #" << ++t << ":\n";
		for (int i=0; i<n; i++)
			cin >> G[i];
			
		for (int y=0; y<n; y++)
		{
			for (int x=0; x<m; x++)
			{
				if (G[y][x]=='*') cout << '*';
				else
				{
					int a=0;
					for (int i=0; i<8; i++)
					{
						int vx = x+tow[i][0], vy = y+tow[i][1];
						if (0<=vx&&vx<m && 0<=vy&&vy<n && G[vy][vx]=='*')
							a++;
					}
					cout << a;
				}
			}
			cout << '\n';
		}
	}
}
