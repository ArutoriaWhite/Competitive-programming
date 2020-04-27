    #include <bits/stdc++.h>
    #define de(x) cout << #x << "=" << x << ", "
    #define dend cout << '\n'
    #define Eriri ios::sync_with_stdio(0), cin.tie(0);
    #define F first
    #define S second
    using namespace std;
    typedef pair<int,int> Pii;
    const int N = 2e5+10;
     
    int eq[N<<2], les[N<<2], gr[N<<2], sum[N], a[N];
    int n, k, t, m, p, res;
     
    inline void calc ()
    {
        res = 1e9;
        for (int i=0; i<=p; i++)
            eq[i] = les[i] = gr[i] = 0;
        for (int i=0,j=n-1; i<j; i++,j--)
            eq[a[i]+a[j]]++;
        for (int i=1; i<=m; i++)
            les[i] = eq[i-1] + les[i-1];
        for (int i=m; i>0; i--)
            gr[i] = eq[i]+gr[i+1];
    }
     
    int main()
    {
        Eriri
        cin >> t;
        while (t--)
        {
            cin >> n >> k, m=k<<2, p=k<<1;
            for (int i=0; i<n; i++)
                cin >> a[i];
            calc();
            for (int x=1; x<=p; x++)
                res = min( res, n/2-eq[x] + gr[2*x] + les[max(0,2*x-2*k)]);
            cout << res << '\n';
        }
    }