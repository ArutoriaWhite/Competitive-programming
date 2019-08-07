#include <string>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <iostream>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define toN(c)  (int)(c)-97
#define toC(n) (char)(n+97)
using namespace std;

int arr[5][5];
string s,w,maxW;
int k;
int maxSum=0,sum;

void Backtracking(int n){
    if(n==4)
    {
        sum=0;
        for(int begin=0 ;begin+k<=s.length() ;begin++)
        {
            int j=0;
            _for(i,begin,begin+k)
            {
                sum+=arr[toN(s[i])][toN((w[j]))];
                j++;
            }
        }
        if(sum>maxSum){
            maxW=w;
            maxSum=sum;
        }
    }
    else
    {
        _for(i,0,5)
        {
            w[n]=toC(i);
            Backtracking(n+1);
        }
    }
}

int main(){
    cin>>s>>k;
    _for(i,0,5){
        _for(j,0,5){
            int tmp;cin>>tmp;
            arr[i][j]=tmp;
        }
    }
    Backtracking(0);
    cout<<maxW<<endl;
    return 0;
}
