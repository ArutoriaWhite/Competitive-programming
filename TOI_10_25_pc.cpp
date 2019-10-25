#include<iostream>
using namespace std;
#define DE cout << "::"
string s[3], tar;
int tlen;

int main()
{
    cin >> tar;
    tlen = tar.size();
    for( int i=0; i<3; i++)
    {
        cin >> s[i];
    }

    int mn = INT_MAX, n;
    for( int i=0; i<3; i++)
    {
        int tmn=INT_MAX;
        for( int j=0,len=s[i].size(); j<len; j++)
        {
            int sum = (j+tlen-len+j)<<1;
            for( int ti=0,si=j; si<len && ti<tlen; ti++,si++)
            {
                if (tar[ti]!=s[i][si]) sum+=3;
            }
            if (sum<tmn)
            {
                tmn=sum;
            }
            DE << tmn << '\n';
        }

        if (tmn<=mn)
        {
            n = i+1;
            mn = tmn;
        }

    }
    cout << n << ' ' << mn;
}
