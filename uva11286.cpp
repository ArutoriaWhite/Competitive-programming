#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
#define M 1000000007

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
	int res=0;
	for (int i=0; i<5; i++)
	{
		int x;
		cin >> arr[i];
	}
	sort(arr,arr+5);
	for (int i=0; i<5; i++)
	{
		res = (res+qpow(arr[i],i))%M;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while (cin >> n)
	{
		if (n==0) return 0;
		memset(cnt,0,sizeof(cnt));
		
		for (int i=0; i<n; i++)
		{
			int k = mhash();
			cnt[k]++;
		}
		
		
		
		cout << ans << '\n';
	}
	return 0;
}

