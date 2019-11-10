#include<iostream>
using namespace std;

int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string wk[7] = { "Monday\n", "Tuesday\n", "Wednesday\n", "Thursday\n", "Friday\n", "Saturday\n", "Sunday\n"};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		int m, d, k;
		cin >> m >> d;
		k=d;
		for (int i=0; i<m-1; i++)
		{
			k += mon[i];
		}
		
		cout << wk[(k+4)%7];
	}
}
