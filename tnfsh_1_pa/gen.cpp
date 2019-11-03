#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("case_c.txt","w",stdout);
    srand(time(NULL));
    int n=7800000, k=rand()%1000;

    cout << n << ' ' << k << '\n';
    for (int i=0; i<n; i++)
    {
        cout << rand()%1000 << ' ';
    }   
}
