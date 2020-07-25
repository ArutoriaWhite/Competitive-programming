#include "Pikachu.h"
#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int n, res, cnt;
vector<int> t, f, x;

/*
int num[(1<<21)];
int Init()
{
    int k, a;
    cin >> k >> a;
    for (int i=1,j=0; i<=k-1; i++)
    {
        if (j == a) j++;
        num[i] = j;
        j++;
    }
    return k;
}
int GetBit (int k, int b)
{
    cnt++;
    if (cnt > 2*n)
    {
        cout << "to many\n";
        return 0;
    }
    return (num[k]&(1<<b));
}
void Answer (int k)
{
    cout << k << '\n';
}
*/

int main()
{
    n = Init();
    for (int i=1; i<=n-1; i++)
        x.push_back(i);
    for (int i=n,j=0; i>0; i>>=1,j++)
    {
        if (!x.size()) break;
        for (auto e: x)
        {
            if (GetBit(e,j)) t.push_back(e);
            else f.push_back(e);
        }
        if (t.size() > f.size())
            x = f;
        else
            x = t, res |= (1<<j);
        t.clear();
        f.clear();
    }
    Answer(res);
}