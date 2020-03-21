#include<iostream>
using namespace std;
#define maxN 1000000

int q[maxN],f,r;
inline void init()
{
	f=0;
	r=0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();

	int T;
	cin >> T;
	while (T--)
	{
		int opr;
		cin >> opr;
		if (opr==1)
		{
			int n;
			cin >> n;
			q[r++] = n;
		}
		else
		{
			if (f<r)
				cout << q[f++] << '\n';
			else
				cout << "empty!\n";
		}
	}
}
