//by Judge
#include<cstdio>
#include<cctype>
#define ll long long
#define rint register int
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int M=2100;

inline ll read(){
    ll x=0,f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}

int n,k,pat;
int head[M];
ll siz[M],dp[M][M],tmp;
struct Edge{ int to,next; ll val; }e[M<<1];

inline void add(rint u,rint v,rint c){ e[++pat]=(Edge){v,head[u],c}, head[u]=pat; }

void dfs(rint u){ 
    siz[u]=1;
    for(rint i=head[u];i;i=e[i].next){
        rint v=e[i].to; if(siz[v]) continue;
        dfs(v); ll c=e[i].val; 
        for(rint a=siz[u];a>=0;--a)  //枚举当前点的以及当前点的其他子树的染色点数 (反向枚举,避免后效性) 
            for(rint b=siz[v];b>=0;--b)  //枚举目前处理的子树的染色点数
            {
                tmp = dp[u][a] + dp[v][b] + c*b*(k-b) + c*(n-k+b-siz[v])*(siz[v]-b);
                dp[u][a+b]=max(dp[u][a+b],tmp);
            }
            /*
                
            */
                // dp[u][a] 其他子树内的点各自独立于当前子树内的点的贡献 
                //dp[v][b] 当前子树内的点各自独立于其他子树内的点的贡献 
                //c*b*(k-b) 当前边对连接当前子树内的染色点与子树外的染色点的贡献
                //c*(n-k+b-siz[v])*(siz[v]-b) 当前边对连接当前子树内的未染色点与子树外的未染色点的贡献 
        siz[u]+=siz[v];
    }
}
int main(){   //主函数里尽是朴素操作
    n=read(),k=read();
    for(rint i=1;i<n;++i){ 
        rint x=read(),y=read(); ll c=read();
        add(x , y , c), add(y , x , c);
    }
    dfs(1), printf("%lld\n",dp[1][k]);
    return 0;
}