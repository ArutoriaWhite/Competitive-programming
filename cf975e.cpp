#include <iostream>
using namespace std;
const int M = 3e5+10;

struct node { int l, r, val=-1, tag; node *ls=NULL, *rs=NULL; } pool[M*40];
int cnt=0;

inline void upd (int k, node *v)
{
    v->val = k*(v->r-v->l);
    if ((v->r)-(v->l) > 1) tag = k;
}
inline void push (node *v)
{
    if (v->ls == NULL) v->ls = &pool[cnt++];
    if (v->rs == NULL) v->rs = &pool[cnt++];
    if (v->tag == -1) return;
    upd(v->tag,v->ls), upd(v->tag,v->rs);
}
inline void pull (node *v)
{
    v->val = v->ls->val + v->rs->val;
}
void modify (int ml, int mr, int k, node *&v)
{
    if (v==NULL) v = &pool[cnt++];
    push(v);
    if (ml<=(v->l) && (v->r)<=mr)
    {
        upd(k,v);
        return;
    }
    int m = (v->l + v->r)>>1;
    if (ml<m) modify(ml,mr,k,v->ls);
    if (mr>m) modify(ml,mr,k,v->rs);
    pull(v);
}
int query (int ql, int qr, node *&v)
{
    if (v == NULL) v = &pool[cnt++];
    puhs(v);
    if (ql<=(v->l) && (v->r)<=(qr))
        return v->val;
    int m = (v->l + v->r)>>1;
    if (ql<m) query(ql,qr,v->ls);
    if (q
}

int main()
{

}