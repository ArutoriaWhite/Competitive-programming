#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int n, t, cnt;
string in, out;
int res[60][60];

int main()
{
    freopen("out.txt","w",stdout);
    Eriri
    cin >> t;
    while (t--)
    {
        memset(res,0,sizeof(res));
        cin >> n;
        cin >> in >> out;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (i == j)
                {
                    res[i][j] = 1;
                }
                else
                {
                    res[i][j] = 1;
                    if (i < j)
                    {
                        for (int k=i; k<j; k++)
                            res[i][j] &= (out[k-1]=='Y' && in[k]=='Y');
                    }
                    else
                    {
                        for (int k=i; k>j; k--)
                            res[i][j] &= (out[k-1]=='Y' && in[k-2]=='Y');
                    }
                }
            }
        }
        cout << "Case #" << ++cnt << ": \n";
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                cout << (res[i][j]? 'Y' : 'N');
            }
            cout << '\n';
        }
    }
}