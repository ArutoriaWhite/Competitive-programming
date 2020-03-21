#include<iostream>
#include<algorithm>
#include<string.h>
#include<unordered_map>
using namespace std;
#define M 1000000007
#define int long long

unordered_map<int,int> cnt;

inline int qpow( int x, int n)
{
	int res=1;
	while (n>0)
	{
		if (n&1) res = (res*x)%M;
		n>>=1;
		x = (x*x)%M;
	}
	return res;
}

inline int mhash()
{
	int arr[5];
	for (int i=0; i<5; i++)
	{
		int x;
		cin >> arr[i];
	}
	sort(arr,arr+5);
	return arr[0] * (int)1e12 + arr[1] * (int)1e9 + arr[2] * (int)1e6 + arr[3] * (int)1e3 + arr[4];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while (cin >> n)
	{
		if (n==0) return 0;
		cnt.clear();
		
		int ans=0, maxcnt=-1;
		for (int i=0; i<n; i++)
		{
			int k = mhash();
			cnt[k]++;
			
			if (cnt[k]==maxcnt)
				ans+=cnt[k];
			else if (cnt[k]>ans)
			{
				ans = cnt[k];
				maxcnt = cnt[k];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

