#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int n;
    while (cin >> s)
    {
        if (s=="-1") break;
        if (sscanf(s.c_str(),"0x%X", &n)==1)
            printf("%d\n",n);
        else
            sscanf(s.c_str(),"%d", &n), printf("0x%X\n",n);
    }
}