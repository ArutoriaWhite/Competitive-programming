#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 25e5, M = 1e6;

int n, m, st[N], ord[M], k;
struct que { int l, r; } q[M];
inline bool cmp ( int a, int b )
{
    return q[a].r-q[a].l < q[b].r-q[b].l;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++)
        scanf("%d%d", &q[i].l, &q[i].r), q[i].l--, ord[i] = i;
    sort(ord,ord+m,cmp);

    for (int i=0; i<n; i++) scanf("%d", &st[i]);
    for (k=0; k<m&&q[ord[k]].r-q[ord[k]].l<=1; k++) q[ord[k]].l = st[q[ord[k]].l];

    for (int j=1; k<m&&(1<<j)<=n; j++)
    {
        for (int i=0; i+(1<<j)<=n; i++)
            st[i] = max( st[i], st[i+(1<<(j-1))] );
        for ( ;k<m&&(q[ord[k]].r-q[ord[k]].l)<(1<<j+1); k++)
            q[ord[k]].l = max( st[q[ord[k]].l], st[q[ord[k]].r-(1<<j)] );
    }

    for (int i=0; i<m; i++)
        printf("%d\n", q[i].l);
}
/*
6 1
1 6
7 3 13 6 1 18 
*/