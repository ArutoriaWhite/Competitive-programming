#include<iostream>
#include<string.h>
using namespace std;
#define int long long
const int N=1<<20;

int heap[N], r;

inline void init()
{
    memset(heap,0x7f,sizeof(heap));
    r = 1;
}

inline void float_up (int x)
{
    while (x>1 && heap[x]<heap[x>>1])
        swap (heap[x], heap[x>>1]), x>>=1;
}

inline void sink (int x)
{
    while (heap[x]>heap[x<<1] || heap[x]>heap[x<<1|1])
    {
        if (heap[x<<1] < heap[x<<1|1])
            swap( heap[x], heap[x<<1] ), x = x<<1;
        else
            swap( heap[x], heap[x<<1|1]), x = x<<1|1;
    }
}

inline void push (int x)
{
    heap[r] = x;
    float_up(r);
    r++;
}

inline int pop ()
{
    int res = heap[1];
    heap[1] = heap[--r];
    sink(1);
    return res;
}

inline void print()
{
    cout << "heap:\n";
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<(1<<i); j++)
            if (heap[j+(1<<i)] == 1e9) cout << 'x' << ' ';
            else cout << j+(1<<i) << ":" << heap[j+(1<<i)] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    int T, opr, n;
    cin >> T;
    while (T--)
    {
        cin >> opr;
        if (opr == 1)
        {
            cin >> n;
            push(n);
        }
        else
        {
            if (r == 1)
                cout << "empty!\n";
            else
                cout << pop() << '\n';
        }
    }
}