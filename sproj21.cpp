#include<iostream>
using namespace std;
#define KILL 0
#define RUSH 1
#define DE cout << " ::"
#define maxN (500000+10)

int to[maxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		to[i] = i+1;
	for (int i=0; i<m; i++)
	{
		int opr, x;
		cin >> opr >> x;
		if (opr==KILL)
		{
			for (int j=0,k=to[j]; k!=0; j=k,k=to[k])
			{
				if (k==x)
				{
					to[j] = to[k];
					break;
				}
			}
		}
		else
		{
			for (int j=0,k=to[j],f=to[k]; f!=0; j=k,k=f,f=to[f])
			{
				if (f==x)
				{
					to[j] = f;
					to[k] = to[f];
					to[f] = k;
					break;
				}
			}
		}
	}
	for (int i=0,j=to[i]; j!=0; i=j,j=to[j])
	{
		cout << j;
		if (to[j]==0) cout << '\n';
		else cout << ' ';
	}
	return 0;
}