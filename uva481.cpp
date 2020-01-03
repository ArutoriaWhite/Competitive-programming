#include<iostream>
using namespace std;

int arr[1000000], q[1000000], r=0;

int main()
{
    int n;
    while (cin >> n)
    {
        r=0;
        for (int i=0; i<n; i++)
            cin >> arr[i];
        q[r++] = arr[0];
        for (int i=1; i<n; i++)
        {
            if (q[r-1]<arr[i]) q[r++] = arr[i];
            else
            {
                int le=0, ri=r-1;
                while (le<ri)
                {
                    int m = (ri+le)/2;
                    if (q[m]<arr[i]) le = m+1;
                    else ri = m;
                }
                q[le] = arr[i];
            }
        }
        cout << r << '\n';
    }
}