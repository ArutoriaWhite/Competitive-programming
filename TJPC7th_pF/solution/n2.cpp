#include <iostream>
using namespace std;
const int N = 1e5+10;

int n, m;
int a[N], b[N], ans, ans_num;

int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        cin >> a[i] >> b[i];
    }
    ans = 2e8;
    for (int i=1; i<=m; i++)
    {
        int len0 = 0, len1 = 1;
        for (int j=1; j<m; j++)
        {
            int k = (i+j-1)%m+1;
            if (b[k] == 1)
                len1 = max(len1, (a[k]-a[i]+n)%n);
            else
                len0 = max(len0, (a[i]-a[k]+n)%n);
        }
        if (ans > max(len0,len1))
        {
            ans = max(len0,len1);
            ans_num = a[i];
        }
    }
    cout << ans_num << ' ' << ans << '\n';
}