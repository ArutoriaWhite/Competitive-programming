#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6;

int a[N], dp[N], from[N], qid[N];
int n, r, res;
inline bool cmp (int x, int y)
{
    return a[x] < a[y];
}
inline void lis()
{
    for (int i=0; i<n; i++)
    {
        int j = lower_bound(qid,qid+r,i,cmp)-qid;
        if (i==0)
            from[i] = -1, qid[r++] = i;
        else if (j==r)
            from[i] = qid[r-1], qid[r++] = i;
        else
            from[i] = qid[j-1], qid[j] = i;
    }
}
inline void print (int i)
{
    if (from[i] != -1)
        print(from[i]);
    cout << a[i] << '\n';
}
/*
dp[i] = max{dp[j] | 0<=j<i, a[j]<a[i]}
*/

int main()
{
    while (cin >> a[n]) n++;
    for (int i=0; i<n; i++)
        dp[i] = 1;
    lis();
    cout << r << '\n' << '-' << '\n';
    print(qid[r-1]);
}