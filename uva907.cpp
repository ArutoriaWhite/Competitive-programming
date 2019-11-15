#include<iostream>
#include<string.h>
using namespace std;

// k := min len
int cam[1000], n, k;
bool suc( int len)
{
	int pro=0, pron=0, cnt=0;
	while(pron<n)
	{
		cnt++;
		pro += len;
		while (pron<n && cam[pron]<pro)
			pron++;
		pro = cam[pron];
	}
	return (cnt<=k);
}

inline int bin( int l, int r)
{
	int s=r;
	while (s>0)
	{
		if (l+s>r || suc(l+s))
			s>>=1;
		else
			l += s;
	}
	return l+1;
}
inline void init()
{
	memset(cam,0,sizeof(cam));
	n=0, k=0;
}
int main() {
	while (cin >> n >> k)
	{
		n++;
		int sum=0, maxx=-1;
		for (int i=0; i<n; i++)
		{
			int x;
			cin >> x;
			maxx = max(x,maxx);
			sum += x;
			cam[i] = x;
		}
		cout << bin(maxx,sum) << '\n';
	}
	return 0;
}

