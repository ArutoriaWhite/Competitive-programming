#include <iostream>
using namespace std;

int sum, a, res, n;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a;
        sum = max(0,sum+a);
        res = max(sum,res);
    }
    cout << res << '\n';
}