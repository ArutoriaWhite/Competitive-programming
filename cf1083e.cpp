    #include <bits/stdc++.h>
    #define de(x) cout << #x << "=" << x << ", "
    #define dd cout << '\n';
    #define rep(i,j,k) for (int i=j; i<=k; i++)
    #define shaaark ios::sync_with_stdio(0), cin.tie(0);
    #define F first
    #define S second
    #define int long long
    #define SZ(x) ((int)x.size())
    using namespace std;
    typedef pair<int,int> pii;
    const int N = 1e6+10;
    /*
    dp[i] = max{ dp[j]+(w[i]-w[j])*h[i] - c[i]}
    dp[i] = max{-w[j]h[i] + dp[j] | 0<j<i} + w[i]h[i] - c[i]
    y = -w[j]*x//:rc[i].h + dp[j], m = -w[j], k=dp[j]
    */
    struct RC {int h, w, c;} rc[N];
    struct Line {int m, k; double rbound=0;} dq[N];
    int dp[N], ans, r, n;

    inline double interX (Line a, Line b)
    {
        return (double)(-a.k+b.k)/(a.m-b.m);
    }
    inline int query (int x)
    {
        if (r<=0) return 0;
        int i=0, s=r-1;
        while (s>0)
        {
            if (i+s>=r || dq[i+s].rbound<x)
                s >>= 1;
            else i += s;
        }
        return dq[i].m*x + dq[i].k;
    }
    inline void insert (int m, int k)
    {
        while (r>=2 && interX({m,k,0},dq[r-2])>=interX(dq[r-1],dq[r-2])) r--;
        double rbound;
        if (r>0) rbound = interX({m,k,0}, dq[r-1]);
        else rbound = interX({m,k,0},{0,0,0});
        dq[r] = {m,k,rbound};
        r++;
    }

    signed main()
    {
        shaaark
        cin >> n;
        rep(i,1,n) cin >> rc[i].w >> rc[i].h >> rc[i].c;
        sort(rc+1,rc+1+n,[](RC i, RC j){return i.w<j.w;});
        rep(i,1,n)
        {
    /*         rep(j,0,r-1)
            {
                de(j), de(dq[j].m), de(dq[j].k), de(dq[j].rbound), dd
            } */
            dp[i] = max(query(rc[i].h),0LL) + rc[i].w*rc[i].h - rc[i].c;
            //de(i), de(query(rc[i].h)), de(rc[i].w*rc[i].h - rc[i].c), de(dp[i]), dd
            ans =  max(ans, dp[i]);
            insert(-rc[i].w, dp[i]);
        }
        cout << ans << '\n';
    }