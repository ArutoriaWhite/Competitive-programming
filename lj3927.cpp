#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
using namespace std;
typedef pair<int,int> pii;
/*
�y n! �b k �T��U��� 0 ������

���X�ӫ�Y 0 �N���������Ʀr�]�t k ���X����

��]�Ƥ��� k
�M����C�ӽ�]�Ƨ�X�����]�t�h�֦ۤv
�M��j�a�� min
*/

signed main()
{
    int n, k;
    cin >> n >> k;
    if (k == 10)
    {
        int cnt2 = 0;
        int cnt5 = 0;
        rep(i,1,n)
        {
            int cnt2 = 0;
            for (int x=i; x&&x%2==0; x/=2)
                cnt2++;
                cnt5++;
        }
        cout << max(cnt2,cnt5) << '\n';
            for (int x=i; x&&x%5==0; x/=5)
    }
    else
    {
        int f = 1;
        rep(i,1,n)
            f *= i;

        int cnt = 0;
        while (f % k == 0)
        {
            f /= k;
            cnt++;
        }
        cout << cnt << '\n';
    }
}
