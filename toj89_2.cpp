#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e5+10;

int e[N], f[N], t, a, b, n;
string s1, s2, s3;
inline void init()
{
    memset(f,-1,sizeof(f));
}
int ff (int x) { return (f[x]==-1? x : f[x]=ff(f[x])); }
inline void Uf (int a, int b)
{
    if (ff(a) == ff(b)) return;
    f[ff(a)] = ff(b);
    e[b] == ff(e[a]);
}
inline void Ue (int a, int b)
{
    if (e[a]!=-1) Uf(e[a],b);
    if (e[b]!=-1) Uf(e[b],a);
    e[a] = ff(b), e[b] = ff(a);
}

int main()
{
    Eriri;
    init();
    cin >> n;
    while (cin >> s1 >> s2 >> s3 >> a >> b)
    {
        if (s1[0]=='y' && s3[0]=='f')
        {
            if (ff(e[a]) == ff(b)) cout << "angry\n";
            else Uf(a,b);
        }
        else if (s1[0]=='y' && s3[0]=='e')
        {
            if (ff(a) == ff(b)) cout << "angry\n";
            else Ue(a,b);            
        }
        else if (s1[0]=='a' && s3[0]=='f')
            cout << (ff(a)==ff(b)? "yeap" : "nope") << '\n';
        else
            cout << (ff(e[a])==ff(b)? "yeap" : "nope") << '\n';
    }
}