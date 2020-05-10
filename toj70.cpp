#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

double r1, r2, i1, i2, r, i;
char opr;

int main()
{
    cin >> r1 >> i1 >> opr >> r2 >> i2;
    if (opr ==  '+')
        r = r1+r2, i = i1+i2;
    if (opr == '-')
        r = r1-r2, i = i1-i2;
    if (opr == '*')
        r = r1*r2+i1*i2*-1, i = r1*i2 + i1*r2;
    if (opr == '/')
    {
        double d = r2*r2 + i2*i2;
        r = r1*r2+i1*i2, i = r1*i2*-1 + r2*i1;
        r /= d, i /= d;
    }
    cout << fixed << setprecision(2) << r ;
    if (i>0) cout << '+';
    cout << i << "i\n";
}