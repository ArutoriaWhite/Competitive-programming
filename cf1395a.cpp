#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define NewYearBurst ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    NewYearBurst
    int a[4], t;
    cin >> t;
    while (t--)
    {
        for (int i=0; i<4; i++) cin >> a[i];
        int flag = 0;
        for (int i=0; i<2; i++)
        {
            int ji = 0;
            for (int j=0; j<4; j++)
            {
                int x = a[j];
                if (j<3) x -= i;
                else x += i*3;
                if (x&1) ji++;
                if (x<0) ji = 3;
            }
            if (ji < 2) flag = 1;
        }
        cout << (flag? "Yes" : "No") << '\n';
    }
}