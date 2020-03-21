#include <iostream>
using namespace std;

int n, k;
string s;

int main()
{
    cin >> n >> k;
    getline(cin,s), getline(cin,s);
    for (int i=0; i<k; i++)
        for (n--; n>0&&s[n-1]!=' '; n--);
    for (int i=0; i<n; i++) cout << s[i];
    cout << "\n";
}
