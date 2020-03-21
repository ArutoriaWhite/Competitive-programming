#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	bool x=(a!=0), y=(b!=0), z;
	cin >> z;
	
	bool flag=1;
	if ((x&y)==z) cout << "AND\n", flag=0;
	if ((x|y)==z) cout << "OR\n", flag=0;
	if ((x^y)==z) cout << "XOR\n", flag=0;
	
	if (flag)
	{
		cout << "IMPOSSIBLE\n";
	}
}
