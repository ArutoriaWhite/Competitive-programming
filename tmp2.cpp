#include<iostream>
using namespace std;

int main()
{
    int g;
    cin>>g;
    int a[g]; // 本題數據較大, 陣列移動到全域
    for (int c=0;c<g;c++)
    {cin>>a[c];}
    int b[g]; // b 應該開 long long
    
    // b[0] 特別處理, d 從 1 開始
    for (int d=0;d<g;d++)
    {b[d]=b[d-1]+a[d];}
    
    int h;
    cin>>h;
    for (int l=h;l>0;l--)
    {int e, f;
    cin>>e>>f;
    e=e-1;
    f=f-1;
    if (e>f)
    {int t=f;f=e;e=t;} // 可以寫 swap(e,f);
    // 如果 e == 0 要特判否則會戳到 b[-1]
    cout<<b[f]-b[e-1]<<'\n';
    }
}