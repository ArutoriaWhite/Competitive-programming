#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
#define maxN 110
#define N 0
#define E 1
#define S 2
#define W 3

int arr[maxN][maxN];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset( arr, 0, sizeof(arr));
        int n, m;
        scanf("%d%d",&n,&m);
        
        for( int x=0; x<=n+1; x++) arr[x][0] = arr[x][n+1] = -1;
        for( int y=0; y<=n+1; y++) arr[0][y] = arr[n+1][y] = -1;

        int k=n*n, cnt=0, f, x, y;
        if (m==1) x=0, y=1, f=E;
        else x=1, y=0, f=S;

        while (cnt<k)
        {
            if (f==E)
            {
                while (arr[x+1][y]==0)
                    arr[x++][y] = ++cnt;
                f = (m==1)? S : N;
            }
            else if (f==W)
            {
                while (arr[x-1][y]==0)
                    arr[x--][y] = ++cnt;
                f = (m==1)? N : S;
            }
            else if (f==N)
            {
                while (arr[x][y-1]==0)
                    arr[x][y--] = ++cnt;
                f = (m==1)? E : W;
            }
            else if (f==S)
            {
                while (arr[x][y-1]==0)
                    arr[x][y--] = ++cnt;
                f = (m==1)? W : E;
            }
            cout << cnt << '\n';
        }

        for( int y=0; y<=n+1; y++)
        {
            for( int x=0; x<=n+1; x++)
            {
                printf("%5d",arr[x][y]);
            }
            cout << '\n';
        }
    }
}