#include<iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n==0) return 0;
        for (int i=01234; i<=98765; i++)
        {
            long long apr = 0;
            int x=i, y=i*n;
            while (x>0)
                apr |= (1<<(x%10)), x/=10;
            while (y>0)
                apr |= (1<<(y%10), y/=10;
            if (x+1 == (1<<10))
            {
                cout 
            } 
        }
    }
}