#include <iostream>
#define DE cout << " ::"
using namespace std;

int a, b, c, d, m, S, T;

inline int run (int t)
{
    int max_val;
    
}

inline int bs()
{
    if (run(0)>=S) return 0;
    if (run(T)<=S) return -1;

    int i=0, s=T;
    while (s>0)
    {
        if (run(i+s)>=S) s>>=1;
        else i += s;
    }
    return i+1;
}

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> a >> b >> c >> d >> m >> S >> T)
    {
        DE << run(T) << '\n';
        int t = bs();
        if (t==-1) cout << "No\n" << run(T) << '\n';
        else cout << "Yes\n" << t << '\n';
    }
}

