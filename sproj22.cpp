#include<iostream>
#include<string.h>
using namespace std;
#define maxN (1000000+10)
#define int long long 

int id[maxN], a[maxN], s[maxN], r, sum;

inline void init()
{
	sum=0;
	r=0;
	memset(s,0,sizeof(s));	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		init();
		
		int n;
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> a[i];
			
		for (int i=0; i<n; i++)
		{
			while (r>0 && a[id[r-1]]<a[i])
				r--, sum++;
				
			if (r>0 && a[id[r-1]] > a[i])
				s[i]++;
				
			else if (r>0 && a[id[r-1]]==a[i])
				s[i] += s[id[r-1]]+1;
				
			id[r++] = i;
			sum += s[i];	
		}
		cout << sum << '\n';
	}
}
