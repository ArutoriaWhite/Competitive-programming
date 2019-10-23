#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int mx=-1;
    for( int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        if (x>mx)
        {
            mx=x;
        }
    }
    cout << fixed << setprecision(4) << (double)mx << '\n';
    if (mx>k)
    {
        cout << "I'm the bone of my sword\n";
    }
    else
    {
        cout << "You have been slain\n";
    }
}