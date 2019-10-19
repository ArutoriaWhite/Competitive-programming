#include<iostream>
using namespace std;
#define maxN 10000000

int to[maxN], val[maxN];
int rear, top; //rear haven't used
inline void init()
{
    rear=0;
    top=0;
}
inline int at( int i) // start from 1
{
    int res=top;
    while (--i)
    {
        res=to[res];
    }
    return res;
}
inline void mv_front( int i)
{
    int pre=at(i-1), cur=to[pre], nex=to[cur];
    to[pre]=nex;
    to[cur]=top;
    top=cur;
}
inline void push_front( int x)
{
    to[rear] = top;
    val[rear] = x;
    top = rear;
    rear++;
}

int main()
{
    init();
    for( int i=0; i<10; i++)
    {
        push_front(i);
    }
    for( int i=1; i<=10; i++)
    {
        cout << val[at[i]] << ' ';
    }
}