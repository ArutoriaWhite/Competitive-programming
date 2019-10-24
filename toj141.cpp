#include<iostream>
using namespace std;
#define isN(x) ('0'<=x&&x<='9')
#define maxN 200

int fir[150];
int calc[maxN], rc;
int stk[maxN], rs;
char opr[maxN], ro;
int n[maxN], rn;
int T, t;
inline void init()
{
    rc=0, rs=0, ro=0, rn=0;
    fir['~']=1;
    fir['&']=2;
    fir['|']=3;
    fir[')']=4;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for( t=0; t<T; t++)
    {
        string s;
        cin >> s;
        int len=s.size();
        for( int i=0; i<len; i++)
        {
            if ('0'<=s[i]&&s[i]<='9')
            {
                int j, num=0, tmp=1;
                for( j=i; j<len&&(isN(s[j+1])); j++);
                for( int k=j; k>=i; k--,tmp*=10)
                {
                    num += (s[k]-'0')*tmp;
                }
                i=j;
                n[rn] = num;
                calc[rc++] = rn;
                rn++;
            }
            else
            {
                opr[ro] = s[i];
                stk[]
            }
        }
    }
}