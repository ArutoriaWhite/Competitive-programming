#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+10;

int ord[200];

string name[N];
int id[N], iden[N], age[N];

inline bool cmp (int a, int b)
{
    if (iden[a]!=iden[b])
        return iden[a]<iden[b];
    if (age[a]!=age[b])
    {
        if (iden[a]==5)
            return age[a]<age[b];
        else
            return age[a]>age[b];
    }
    return name[a]<name[b];

}
int main()
{
    ord['e']=1, ord['n']=2, ord['k']=3, ord['w']=4;
    ord['a']=5, ord['m']=6, ord['d']=7, ord['l']=8;

    int n, m;
    string tmp;
    while (cin >> n >> m)
    {
        m = min(n,m);
        for (int i=0; i<n; i++)
        {
            id[i]=i;
            cin >> name[i] >> tmp >> age[i];
            if ('A'<=tmp[0]&&tmp[0]<='Z') tmp[0] = 'a'+tmp[0]-'A';
            iden[i] = ord[tmp[0]];
        }

        sort(id,id+n,cmp);

        for (int i=0; i<m; i++)
            cout << name[id[i]] << '\n';
    }
}