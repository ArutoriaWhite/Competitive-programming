#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int n = 999;

int main()
{
    freopen("test5.txt","w",stdout);
    mt19937 mt = std::mt19937(); //使用mt19937引擎
    uniform_int_distribution<int> dis(-100,200);
    auto rand = bind(dis,mt);

    cout << n << '\n';
    for (int i=0; i<n; i++)
        cout << rand() << "\n "[i+1<n];
}