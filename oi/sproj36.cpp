#include<iostream>
using namespace std;
#define maxN 10000000

int stk[maxN], r;
inline void init()
{
	r=0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();

	int T;
	cin >> T;
	for (int i=0; i<T; i++)
	{
		char opr;
		cin >> opr;
		if (opr=='1')
		{
			int x;
			cin >> x;
			stk[r++] = x;
		}
		else
		{
			if (r>0)
				cout << stk[--r] << '\n';
			else
				cout << "empty!\n";
		}
	}
}
