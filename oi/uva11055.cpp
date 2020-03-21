#include<iostream>
using namespace std;

int pri[40];

int calcpri( int x, int n)
{
	int res=0;
	while (x>0)
	{
		res += pri[x%n];
		x/=n;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	bool fir=1;
	for (int t=1; t<=T; t++)
	{
		if (fir) fir=0;
		else cout << '\n';
		cout << "Case " << t << ":\n";
		
		for (int i=0; i<36; i++)
			cin >> pri[i];
			
		int n;
		cin >> n;
		for (int i=0; i<n; i++)
		{
			int x;
			cin >> x;
			int minpri = 0x3f3f3f3f, minbas[40], r=0;
			for (int j=2; j<=36; j++)
			{
				int p = calcpri(x,j);
				if (p<minpri)
				{
					minpri = p;
					r=0;
					minbas[r++] = j;
				}
				else if (p==minpri)
				{
					minbas[r++] = j;
				}
			}
			cout << "Cheapest base(s) for number " << x << ": ";
			for (int j=0; j<r; j++)
			{
				cout << minbas[j];
				if (j+1<r) cout << ' ';
				else cout << '\n';
			}
		}
	}
	return 0;
}
