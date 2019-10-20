#include<iostream>
using namespace std;

int F[4][2] = { {0,-1}, {1,0}, {0,1}, {-1,0}};

int main()
{
    int a, b;
    cin >> a >> b;
    for( int i=0; i<4; i++)
    {
        cout << a+F[i][0] << ' ' << b+F[i][1] << '\n';
    }
}