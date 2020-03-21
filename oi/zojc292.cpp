#include<iostream>
using namespace std;
#define W 0
#define N 1
#define E 2
#define S 3

int arr[60][60];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, f;
    cin >> n >> f;
    for( int y=0; y<n; y++)
    {
        for( int x=0; x<n; x++)
        {
            cin >> arr[y][x];
        }
    }

    int cnt=0, step=1, k=0, x=n>>1, y=n>>1;
    while (cnt<n*n-1)
    {
        int sx, sy;
        if      (f==W) sx=-1, sy=0, f=N;
        else if (f==N) sx=0, sy=-1, f=E;
        else if (f==E) sx=1, sy=0, f=S;
        else if (f==S) sx=0, sy=1, f=W;

        for( int i=0; i<step; i++,x+=sx,y+=sy)
        {
            cout << arr[y][x];
            cnt++;
        }
        if (k&1) step++;
        k++;
    }
}