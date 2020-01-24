#include <iostream>
using namespace std;

int a=10, b=20, *natori;

inline void change (int *&n)
{
    n = &b;
}

int main()
{
    natori = &a;
    change(natori);
    cout << *natori << '\n';
}