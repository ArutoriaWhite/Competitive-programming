#include<iostream>
#include<memory.h>
#include<iomanip>
using namespace std;
const int maxA=1e7+10;

int to[maxA], rear[1010], team[maxA];

inline void init()
{
    memset(to,-1,sizeof(to));
    memset(rear,-1,sizeof(rear));
    memset(team,-1,sizeof(-1));
    rear[0] = 0;
}

inline void pri_to()
{
    cout << "id:";
    for (int i=0; i<10; i++)
        cout << setw(3) << i;
    cout << '\n';

    cout << "to:";
    for (int i=0; i<10; i++)
        cout << setw(3) << to[i];
    cout << '\n';

}

inline void pri_que()
{
    cout << "que: ";
    for (int i=to[0]; i!=-1; i=to[i])
        cout << setw(3) << i;
    cout << "\n\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, T=1;
    while (cin >> n)
    {
        cout << "Line #" << T++ << "\n";
        init();
        for (int i=1; i<=n; i++)
        {
            int m;
            cin >> m;
            for (int j=0; j<m; j++)
            {
                int x;
                cin >> x;
                team[x] = i;
           }
        }

        string cmd;
        while (cin >> cmd)
        {
            if (cmd[0] == 'E')
            {
                int x;
                cin >> x;
                if (team[x]==-1)
                {
                    to[ rear[0] ] = x;
                    rear[0] = x;
                }
                else if (rear[team[x]]==-1 || rear[team[x]]==rear[0])
                {
                    to[ rear[0] ] = x;
                    rear[0] = rear[team[x]] = x;
                }
                else
                {
                    to[x] = to[rear[team[x]]];
                    to[ rear[team[x]] ] = x;
                    rear[team[x]] = x;
                }
            }
            else if (cmd[0] == 'D')
            {
                cout << to[0] << '\n';
                if (to[0] == rear[0])
                    rear[0] = 0;
                if (to[0] == rear[team[to[0]]])
                    rear[team[to[0]]] = -1;
                to[0] = to[to[0]];
            }
            else break;
        }
    }
}