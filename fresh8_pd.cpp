#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

string a, s, bin, ans;
int num[10010], k;

inline int ston (string &x, int op, int ed)
{
    int res = 0;
    for (int i=op; i<ed; i++)
        res*=10, res += x[i]-'0';
    return res;
}
inline int bton (string &x, int op, int ed)
{
    int res = 0;
    for (int i=op,j=0; i<ed; i++,j++)
        if (x[i] == '1')
            res |= (1<<j);
    return res;
}

signed main()
{
    Eriri
    getline(cin,s);
    k = __lg(s.size()+1);
    cin >> a;
    for (int i=0,j=a.size(); j>0; j-=10,i++)
        num[i] = ston(a,j-10,j);
    for (int i=0; i<a.size()/10; i++)
        for (int j=0; j<32; j++,num[i]>>=1)
            bin += (num[i]&1? "1" : "0");
    while (bin.size()%32) bin += "0";
    for (int i=0; i<bin.size(); i+=k)
    {
        int x = bton(bin,i,i+k);
        if (x == 0) ans += '\n';
        else ans += s[x-1];
    }
    for (int i=ans.size()-1; i>=0; i--)
        cout << ans[i];
    cout << '\n';
}