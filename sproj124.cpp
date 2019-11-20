#define M1 mx-1,my
#define M2 mx-1,my-1
#define M3 mx,my-1
#define M4 mx,my
#define B1 bx,my
#define B2 bx,by
#define B3 mx,by
#define B4 mx,my
void msol (int n, int bx, int by, int fx, int fy)
{
	if (n==1) return;
	// middle x, middle y
	int mx = bx+(n>>1), my = by+(n>>1);
	if (fx>=mx && fy>=my) // 4
	{
		Report(M1,M2,M3);
		msol(n>>1,B1,M1);
		msol(n>>1,B2,M2);
		msol(n>>1,B3,M3);
		msol(n>>1,B4,fx,fy);
	}
	else if (fx>=mx && fy<my) //3
	{
		Report(M1,M2,M4);
		msol(n>>1,B1,M1);
		msol(n>>1,B2,M2);
		msol(n>>1,B4,M4);
		msol(n>>1,B3,fx,fy);
	}
	else if (fx<mx && fy>=my) // 1
	{
		Report(M2,M3,M4);
		msol(n>>1,B2,M2);
		msol(n>>1,B3,M3);
		msol(n>>1,B4,M4);
		msol(n>>1,B1,fx,fy);
}
	else if (fx<mx && fy<my) // 2
	{
		Report(M1,M3,M4);
		msol(n>>1,B1,M1);
		msol(n>>1,B3,M3);
		msol(n>>1,B4,M4);
		msol(n>>1,B2,fx,fy);
	}
}


void solve (int n, int x, int y)
{
	msol(n,1,1,x,y);
}
