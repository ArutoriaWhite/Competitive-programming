#include<iostream>
using namespace std;

int natori[3][300], r[3], cnt;

void print()
{

}
void move (int n, int from, int by, int to)
{
	if (n==1)
	{
		if (cnt<=0) return;
		natori[to][r[to]++] = natori[from][r[from]];
		r[from]--;
		cnt--;
		print();
		return;
	}

	
}

int main()
{
	int n;
	while (cin >> n >> cnt)
	{
		print();
		move(n,0,1,2);
	}
}
