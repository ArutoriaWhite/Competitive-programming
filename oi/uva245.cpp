#include<iostream>
using namespace std;
#define maxN 10000000

int to[maxN];
string val[maxN];
int rear, top;
inline void init()
{
    rear=0;
    top=0;
}
inline int at( int i) // start from 1, count back
{
    int res=top;
    while (--i&&res)
    {
        res=to[res];
    }
    return res; // return 0 := over
}
inline void mv_front( int i)
{
    if(i<=1) return;
    int pre=at(i-1), cur=to[pre], nex=to[cur];
    to[pre]=nex;
    to[cur]=top;
    top=cur;
}
inline void push_front( string &x)
{
    rear++;
    to[rear] = top;
    val[rear] = x;
    top = rear;
}

inline bool isAlpha( char &c)
{
    return ('a'<=c&&c<='z') || ('A'<=c&&c<='Z');
}
inline bool isNum( char &c)
{
    return ('0'<=c&&c<='9');
}
inline int toNum( char &c)
{
    return (c-'0');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin,s))
    {
        if (s=="0") break;
        
        int len=s.size();
        for( int i=0; i<len; i++)
        {
            if (isAlpha(s[i]))
            {
                string letter;
                int j;
                for( j=i; isAlpha(s[j]); j++)
                {
                    letter+=s[j];
                }
                i=j-1;
                push_front(letter);
                cout << letter;
            } 
            else if (isNum(s[i]))
            {
                int num[10], j, r, sum=0;
                for( j=i,r=0; isNum(s[j]); j++)
                {
                    num[r++] = toNum(s[j]);
                }
                for( int t=1; r>0; t*=10)
                {
                    sum += num[--r]*t;
                }
                i=j-1;
                cout << val[at(sum)];
                mv_front(sum);
            }
            else
            {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}