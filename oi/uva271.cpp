#include<iostream>
using namespace std;
#define maxN 10000000

int rear;
int stk[maxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin,s))
    {
        rear=0;
        int len=s.size();
        for( int i=0; i<len; i++)
        {
            if (s[i]=='N')
            {
                stk[rear++] = -1;
            }
            else if (s[i]=='C' || s[i]=='D' || s[i]=='E' || s[i]=='I')
            {
                stk[rear++] = -2;
            }
            else if ('p'<=s[i]&&s[i]<='z')
            {
                stk[rear++] = 1;
            }

            if (rear<2) continue;
            while (stk[rear-1]>0&&stk[rear-2]<0)
            {
                if (stk[rear-2]==-1)
                {
                    stk[(--rear)-1] = 1;
                }
                else if (stk[rear-2]==-2)
                {
                    stk[(--rear)-1] = -1;
                }
            }
        }
        if (rear==1&&stk[0]==1) cout << "YES\n";
        else cout << "NO\n";
    }
}
