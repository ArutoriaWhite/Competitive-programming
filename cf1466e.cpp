#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

const int N = 5e5+10, D = 1e9+7, M = 64;
int a[N], n, t, cnt[M], res[M];

int convert_to_int ()
{
    int ans = 0;
    for (int i=0,tt=1; i<M; i++,tt=tt*2%D)
        ans = (res[i]*tt%D + ans)%D;
    return ans;
}
int calc_and (int w)
{
    for (int i=0,x=a[w]; i<M; i++,x>>=1)
    {
        if (x&1)
            res[i] = cnt[i];
        else
            res[i] = 0;
    }
    return convert_to_int();
}
int calc_or (int w)
{
    for (int i=0,x=a[w]; i<M; i++,x>>=1)
    {
        if (x&1)
            res[i] = n;
        else
            res[i] = cnt[i];
    }
    return convert_to_int();    
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin >> n;
        rep(i,1,n)
            cin >> a[i];

        rep(i,1,n)
            for (int j=0,x=a[i]; j<M; j++,x>>=1)
                if (x&1)
                    cnt[j]++;

        int ans = 0;
        rep(i,1,n)
        {
            int suma = calc_and(i);
            int sumo = calc_or(i);
            ans = (ans+suma*sumo%D)%D;
        }
        cout << ans << '\n';
    }
}
/*
8
2
1 7
3
1 2 4
4
5 5 5 5
5
6 2 2 1 0
1
0
1
1
6
1 12 123 1234 12345 123456
5
536870912 536870911 1152921504606846975 1152921504606846974 1152921504606846973

1
2 1 7
*/