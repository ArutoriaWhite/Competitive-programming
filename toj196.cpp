#include <iostream>
#include <stdio.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
using namespace std;
const int N = 1e6+10;

inline int redn() {
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int cnt[N<<1], a[N];

signed main()
{
	int s=redn();
	rep(i,1,s) a[i]=redn();
	int q=redn();
	rep(i,1,s) rep(j,1,s) cnt[a[i]+a[j]]=1;
	rep(i,1,q) printf((cnt[redn()]? "yes\n":"no\n"));
}
