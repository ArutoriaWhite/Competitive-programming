#include<iostream>
using namespace std;

int f (int n, int k)
{
    if (n<=k) return (k-1)%n;
    else return (f(n-1,k)+k)%n;
}

int main()
{
    int T, t=0;
    cin >> T;
    while (t<T)
    {
        int n, k;
        cin >> n >> k;
        cout << "Case " << ++t << ": " << f(n,k)     << "\n";
    }
}