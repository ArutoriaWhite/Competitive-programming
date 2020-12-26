#include <bits/stdc++.h>
#define get_sz(u) (u? u->sz : 0)
#define de(u) cout << #u << " val: " << (u? u->v : 0) << " ls: " << (u? get_sz(u->l) : 0) << " rs: " << (u? get_sz(u->r) : 0) << '\n';
using namespace std;
const int N = 1e5;

struct Node
{
    Node *l, *r;
    int v, pr, sz;
    Node (int _v=0): v(_v), l(0), r(0), pr(rand()), sz(1){}
    void pull (){
        sz = get_sz(l) + get_sz(r) + 1;
    }
} *rt;
void split (Node *u, int k, Node* &pf, Node* &sf)
{
    if (!u) pf = sf = 0;
    else if (k <= get_sz(u->l))
        sf = u, split(u->l,k,pf,sf->l), u->pull();
    else
        pf = u, split(u->r,k-1-get_sz(u->l),pf->r,sf), u->pull();
}
Node* merge (Node* pf, Node *sf)
{
    if (!pf || !sf) return (pf? pf : sf);
    if (pf->pr < sf->pr)
    {
        pf->r = merge(pf->r,sf);
        pf->pull();
        return pf;
    }
    else
    {
        sf->l = merge(pf,sf->l);
        sf->pull();
        return sf;
    }
}
void ins (int p, int x)
{
    Node *pf, *sf, *nw = new Node(x);
    split(rt,p,pf,sf);
    cout << p << '\n';
    de(rt);
    de(pf);
    de(sf);
    de(nw);
    rt = merge(merge(pf,nw),sf);
    de(rt);
}
void del (int p)
{
    Node *pf, *sf, *pf2, *sf2;
    split(rt,p-1,pf,sf);
    split(sf,1,pf2,sf2);
    delete pf2;
    rt = merge(pf,sf2);
}
void print (Node *u)
{
    if (u)
    {
        if (u->l) print(u->l);
        cout << u->v << '\n';
        if (u->r) print(u->r);
    }
}
int main()
{
    char o; int x;
    while (cin >> o)
    {
        if (o == 'i')
            cin >> x, ins(get_sz(rt),x);
        else if (o == 'd')
            cin >> x, del(x);
        else print(rt);
    }
}