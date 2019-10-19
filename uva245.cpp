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
inline void push_front( int x)
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
inline int toN( char &c)
{
    return (c-'0');
}

int main()
{
    string s;
    while (getline(cin,s))
    {
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
            }
            else (isNum(s[i]))
            {
                int sum=0;
                int j;
                for( j=i,t=1; isNum(s[j]); j++,t*=10)
                {
                    sum += toNum(s[i])*t;
                }
                int realsum=0;
                while (sum>0)
                {

                }
            }
        }
    }
}