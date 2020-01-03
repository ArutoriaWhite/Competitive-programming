#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int v[100];

int main()
{
    int n, x;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> v[i];

    cin >> x;
    *(lower_bound(v,v+n,x)-1)=1;
    for (int i=0; i<n; i++)
        cout << v[i] << ' ';
    cout << '\n';
}

// vector
// x<s[0], lwb(x) = s.begin();
// s.back()<x, lwb(x) = s.end();

// array
// x<s[0], 
