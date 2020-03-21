#include<iostream>
using namespace std;
#define N 0
#define E 1
#define S 2
#define W 3

bool fall[55][55];
int mx, my, x, y, F;
string cmd;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> mx >> my;
    while (cin >> x >> y)
    {
		char a;
		cin >> a >> cmd;
		if (a=='N')      F=N;
		else if (a=='E') F=E;
		else if (a=='S') F=S;
		else if (a=='W') F=W;
		
		bool flag=0;
        for (int i=0,len=cmd.size(); i<len; i++)
        {
            if (cmd[i]=='R')
            {
                F = (F+1)%4;
            }   
            else if (cmd[i]=='L')
            {
                F = (F-1+4)%4;
            }   
            else if (cmd[i]=='F')
            {
                int tmpx=x, tmpy=y;
                if (F==N)
                {
                    tmpy++;
                }   
                else if (F==S)
                {
                    tmpy--;
                }
                else if (F==E)
                {
                    tmpx++;
                }
                else if (F==W)
                {
                    tmpx--;
                }

                if (tmpx>mx||tmpy>my||tmpx<0||tmpy<0)
                {
					if (fall[x][y]) continue;
					flag=1;
           			fall[x][y]=1;
		   			break;
                }
				x=tmpx, y=tmpy;
            }   
        }

		cout << x << ' ' << y << ' ';
		if (F==N) cout << 'N';
		if (F==E) cout << 'E';
		if (F==W) cout << 'W';
		if (F==S) cout << 'S';

		if (flag) cout << " LOST";
		cout << '\n';
	}
}
