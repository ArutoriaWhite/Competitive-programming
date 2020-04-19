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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 100;

int arr[N], n, k, res = -1;

int main()
{
    yukari;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        for (int j=0; j<k; j++)
            cin >> arr[j*n+i];
    for (int i=0; i<n*k; i++)
    {
        if (arr[i] == i+1)
        {
            res = i+1;
            break;
        }
    }
    cout << res << '\n';
}