#include<iostream>
using namespace std;
#define maxA ((int)1e7 + 100)

// sagiriisor
int sagiri[maxA];
void build()
{	
	sagiri[1] = 1;
	for (int i=2; i<maxA; i++)
	{
		if (sagiri[i]!=0) continue;
		sagiri[i] = i;
		for (int j=i<<1; j<maxA; j+=i)
		{
			sagiri[j] = i;
		}
	}
}

inline int sec (int x)
{
	int tmp=x;
	while (tmp%sagiri[x]==0) tmp/=sagiri[x];
	return sagiri[tmp];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	build();
	
	int T, x;
	cin >> T;
	while (T--)
	{
		cin >> x;
		cout << sec(x) << ' ' << sagiri[x] << '\n';
	}
}
