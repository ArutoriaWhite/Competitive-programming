#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

priority_queue<int,vector<int>,less<int> > mxh;
priority_queue<int,vector<int>,greater<int> > mnh;
int q, k;

signed main()
{
    Eriri
    cin >> q >> k;
    for (int i=0,x,y; i<q; i++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            mxh.push(y);
            if (mxh.size() > k)
            {
                int a = mxh.top();
                mxh.pop();
                mnh.push(a);
            }
        }
        else
        {
            if (mxh.size() < k) cout << -1 << '\n';
            else
            {
                int a = mxh.top();
                mxh.pop();
                cout << a << '\n';
                if (mxh.size() < k && !mnh.empty())
                {
                    int b = mnh.top();
                    mnh.pop();
                    mxh.push(b);
                }                
            }
        }
    }
}