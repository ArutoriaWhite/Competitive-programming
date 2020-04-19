#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 110;

string name[N], staff[N], west[N];
int se[N], cla[N], paper[N], mx, res, sum, n;

int calc (int i)
{
    int ans = 0;
    if (se[i]>80 && paper[i]>0)
        ans += 8000;
    if (se[i]>85 && cla[i]>80)
        ans += 4000;
    if (se[i]>90)
        ans += 2000;
    if (se[i]>85 && west[i]=="Y")
        ans += 1000;
    if (cla[i]>80 && staff[i]=="Y")
        ans += 850;
    return ans;
}

int main()
{
    yukari;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> name[i] >> se[i] >> cla[i];
        cin >> staff[i] >> west[i] >> paper[i];
    }
    for (int i=0; i<n; i++)
    {
        int x = calc(i);
        if (x > mx)
        {
            res = i;
            mx = x;
        }
        sum += x;
    }
    cout << name[res] << '\n' << mx << '\n' << sum << '\n';
}