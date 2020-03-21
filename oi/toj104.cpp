#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=1,j=n-1; j>=0; i+=2,j--)
    {
        cout << setw(j) << setfill(' ') << "";
        cout << setw(i) << setfill('*') << "";
        cout << '\n';
    }
}
/*
   *
  ***
 *****
*******
*/