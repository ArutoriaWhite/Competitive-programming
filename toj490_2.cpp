#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

Pii stk[N];
int r, n, q, arr[N];

int main()
{
    Eriri
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    cin >> q;
    for (int i=0,a,b; i<q; i++)
    {
        for (cin >> a >> b; r>0 && stk[r-1].F<=a; r--);
        stk[r++] = {a,b};
    }
    int j=0;
    for (int i=r-1; i>=0; i--)
        for ( ;j<stk[i].F; j++)
            cout << stk[i].S << ' ';
    for ( ; j<n; j++) cout << arr[j] << ' ';
    cout << '\n';
}
/*
5
0 0 0 0 0
3
4 1
2 2
3 3

5 
1 1 1 4 1 
5 
3 2 
3 1 
3 3 
1 1 
2 4
*/