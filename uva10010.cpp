#include<iostream>
#include<cstring>
using namespace std;
#define maxN 60
#define DE cout << " ::"

char arr[maxN][maxN];

inline bool check( int x, int y, int a, int b, string &s)
{
    int len=s.size();
    for( int i=0; i<len; i++,x+=a,y+=b)
    {
        if (arr[x][y]!=s[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt","r",stdin);

    int T;
    cin >> T;
    while (T--)
    {
        memset( arr, 0, sizeof(arr));
        int m, n;
        cin >> m >> n;
        for( int y=1; y<=m; y++)
        {
            for( int x=1; x<=n; x++)
            {
                cin >> arr[x][y];
                if ('A'<=arr[x][y]&&arr[x][y]<='Z')
                {
                    arr[x][y]+=('a'-'A');
                }
            }
        }

        int k;
        cin >> k;
        while (k--)
        {
            string s;
            cin >> s;
            bool flag=1;

            for( int y=1; (y<=m)&&flag; y++)
            {
                for( int x=1; (x<=n)&&flag; x++)
                {
                    for( int a=-1; (a<=1)&&flag; a++)
                    {
                        for( int b=-1; (b<=1)&&flag; b++)
                        {
                            DE << x << y << '\n';
                            if( a==b && b==0) continue;
                            if (check(x,y,a,b,s))
                            {
                                DE << arr[x][y] << ' ' << s[0] << ' ';
                                DE << y << ' ' << x << '\n';
                                flag=0;
                            }
                        }
                    }
                }
            }
        }
    }
}