// square len, base x, base y, filled x, filled y
void msol (int n, int bx, int by, int fx, int fy)
{
	if (n==1) return;
	// middle x, middle y
	int mx = bx+(n>>1), my = by+(n>>1);
	if (fx>=mx && fy>=my) // 4
	{
		Report(mx-1,my,mx-1,my-1,mx,my-1);
		msol(n>>1,bx,my,mx-1,my);
		msol(n>>1,bx,by,mx-1,my-1);
		msol(n>>1,mx,by,mx,my-1);
		msol(n>>1,mx,my,fx,fy);
	}
	else if (fx>=mx && fy<my) //3
	{
		Report(mx-1,my,mx-1,my-1,mx,my);
		msol(n>>1,bx,my,mx-1,my);
		msol(n>>1,bx,by,mx-1,my-1);
		msol(n>>1,mx,my,mx,my);
		msol(n>>1,mx,by,fx,fy);
	}
	else if (fx<mx && fy>=my) // 1
	{
		Report(mx-1,my-1,mx,my-1,mx,my);
		msol(n>>1,bx,by,mx-1,my-1);
		msol(n>>1,mx,by,mx,my-1);
		msol(n>>1,mx,my,mx,my);
		msol(n>>1,bx,my,fx,fy);
	}
	else if (fx<mx && fy<my) // 2
	{
		Report(mx-1,my,mx,my-1,mx,my);
		msol(n>>1,bx,my,mx-1,my);
		msol(n>>1,mx,by,mx,my-1);
		msol(n>>1,mx,my,mx,my);
		msol(n>>1,bx,by,mx-1,my-1);
	}
}


void solve (int n, int x, int y)
{
	msol(n,1,1,x,y);
}

