#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

priority_queue< int, vector<int>, less<int> > f;
priority_queue< int, vector<int>, greater<int> > r;
int n;

int main()
{
    Eriri
    cin >> n;
    for (int i=1,u; i<=n; i++)
    {
        cin >> u;
        if (f.empty() || u<=f.top()) f.push(u);
        else r.push(u);
        while (f.size() - r.size() > 1) r.push(f.top()), f.pop();
        while (f.size() - r.size() <= 0) f.push(r.top()), r.pop();
        if (i&1)
            cout << f.top() << '\n';
    }
}