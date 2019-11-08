#include<iostream>
using namespace std;

int colo[3][3];
int s;
char c[] = { 'B', 'C', 'G'};

int main() {
	
	while (cin >> colo[0][0])
	{
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				if (j==0&&i==0) continue;
				cin >> colo[i][j];
				s += colo[i][j];
			}
		}
		
	
		
		int ord[3];
		int m=0x3f3f3f3f;
		
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				if (i==j) continue;
				for (int k=0; k<3; k++)
				{
					if (k==i||k==j) continue;
					int tmp = s-colo[0][i]-colo[1][j]-colo[2][k];
					if (tmp<m)
					{
						m = tmp;
						ord[0] = i, ord[1] = j, ord[2] = k;
					}
				}
			}
		}
		
		cout << m << '\n';
		for (int i=0; i<3; i++)
		{
			cout << ord[i] << ' ';
		}
		cout << '\n';
		
	}
	
	return 0;
}

