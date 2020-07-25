#include <iostream>
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6;

int f[N] = {0, 1, 2, 3, 4, 6}, n;

int main()
{
    Eriri
    for (int i=6; i<N; i++)
        f[i] = f[i/5 + i%5] + i/5*5;
    cin >> n;
    cout << f[n] << '\n';
}