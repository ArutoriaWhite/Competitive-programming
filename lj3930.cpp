#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
using namespace std;
typedef pair<int,int> pii;

/*
�� n*n ���ѽL�M�W�����¦�X�l�A�i�_���a�@�ӥ��M�h�α����
1. �i�H�������M�A���������L�H�������d��]�n���s�p��
2. ���M�����
3. �Y����b���M�л\�]�n�������O�@��

n <= 50, �̦h�����M�´� (2 root, 2 kight, 1 king, 1 queen, 8 pawns

���Ҽ{�M�h�Y�M�h
�u�Ҽ{�M�h�Y�ӦZ
�M�h�Y���ӦZ��:
    1. �i��L�ӦZ���A
    2. ���ӦZ���A

�靈�L�ӦZ�U�y�@�Ӫ��A bfs

enum 1..n as i
    enum 1..n as j
        if is king
        color eight side in G[0], G[1]
            ed = i,j
        if is kight
            color eight side in G[0], G[1]
        if is queen
            color row, col, slides in G[1]
        if is my knight
            op = i,j

queue, dep
bfs()
    get u from q
    if u == ed return dep
    enum next step as ni, nj
        if G[0/1][ni][nj] continue
        if (queen alive && ni,nj is queen)
            change new state to queen die
        push, set dep
*/
const int N = 55;
int G[2][N][N];
int sh[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int shking[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
char s[N][N];
int edr, edc, opr, opc, n;

void build()
{
    memset(G,0,sizeof(G));
    int cnt = 0;
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            if (s[i][j] == 'X')
            {
                edr = i;
                edc = j;
                for (int k=0; k<8; k++)
                {
                    int ni = i+shking[k][0];
                    int nj = j+shking[k][1];
                    if (1<=ni&&ni<=n && 1<=nj&&nj<=n)
                        G[0][ni][nj] = G[1][ni][nj] = 1;
                }
            }
            if (s[i][j] == 'K')
            {
                for (int k=0; k<8; k++)
                {
                    int ni = i+sh[k][0];
                    int nj = j+sh[k][1];
                    if (1<=ni&&ni<=n && 1<=nj&&nj<=n)
                    {
                        G[0][ni][nj] = G[1][ni][nj] = 1;
                    }
                }
            }
            if (s[i][j] == 'Q')
            {
                int owo = G[1][i][j];
                for (int ni=i,nj=j; 1<=ni&&ni<=n&&1<=nj&&nj<=n; ni++)
                    G[1][ni][nj] = 1;
                for (int ni=i,nj=j; 1<=ni&&ni<=n&&1<=nj&&nj<=n; ni--)
                    G[1][ni][nj] = 1;
                for (int ni=i,nj=j; 1<=ni&&ni<=n&&1<=nj&&nj<=n; nj++)
                    G[1][ni][nj] = 1;
                for (int ni=i,nj=j; 1<=ni&&ni<=n&&1<=nj&&nj<=n; nj--)
                    G[1][ni][nj] = 1;
                for (int ni=i,nj=j; 1<=ni&&ni<=n&&1<=nj&&nj<=n; ni++,nj++)
                    G[1][ni][nj] = 1;
                for (int ni=i,nj=j; 1<=ni&&ni<=n&&1<=nj&&nj<=n; ni++,nj--)
                    G[1][ni][nj] = 1;
                for (int ni=i,nj=j; 1<=ni&&ni<=n&&1<=nj&&nj<=n; ni--,nj++)
                    G[1][ni][nj] = 1;
                for (int ni=i,nj=j; 1<=ni&&ni<=n&&1<=nj&&nj<=n; ni--,nj--)
                    G[1][ni][nj] = 1;
                G[1][i][j] = owo;
                cnt++;
                assert(cnt>1);
            }
            if (s[i][j] == 'O')
            {
                opr = i;
                opc = j;
            }
        }
    }
}

int dep[2][N][N];
int bfs()
{
    queue<int> qr, qc, qs;
    if (G[1][opr][opc])
        return -1;
    memset(dep,-1,sizeof(dep));
    qs.push(1);
    qr.push(opr);
    qc.push(opc);
    dep[1][opr][opc] = 0;

    while (!qr.empty())
    {
        int cs = qs.front(); qs.pop();
        int cr = qr.front(); qr.pop();
        int cc = qc.front(); qc.pop();

        //de(cs), de(cr), de(cc), de(dep[cs][cr][cc]), dd;

        if (cr==edr && cc==edc)
            return dep[cs][cr][cc];

        for (int i=0; i<8; i++)
        {
            int nr = cr + sh[i][0];
            int nc = cc + sh[i][1];
            int ns = cs;
            if (nr<1 || nr>n || nc<1 || nc>n)
                continue;
            if (ns==1 && s[nr][nc]=='Q')
                ns = 0;

            //de(nr), de(nc), de(G[ns][nr][nc]), de(dep[ns][nr][nc]), dd;

            if (G[ns][nr][nc] || dep[ns][nr][nc]>=0)
                continue;
            qs.push(ns);
            qr.push(nr);
            qc.push(nc);
            dep[ns][nr][nc] = dep[cs][cr][cc] + 1;
        }
    }
    return -1;
}

signed main()
{
    while (cin >> n)
    {
        rep(i,1,n)
            rep(j,1,n)
                cin >> s[i][j];
        build();

        cout << bfs() << '\n';
    }
}
