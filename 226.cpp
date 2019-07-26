#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main ()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T;cin>>T;
    while(T--){

        vector<int> numsArray;
        long long n; cin>>n;
        long long sum=0;
        long long tmpN=n;
        bool isMutiple=false,hasZero=false;


        while(tmpN>0){
            int tmp=tmpN%10;
            tmpN/=10;
            if(tmp==0) hasZero=true;
            numsArray.push_back(tmp);
            sum=(sum+tmp%3)%3;
        }
        if(sum%3==0 && hasZero) isMutiple=true;

        if(isMutiple){
            sort(numsArray.begin(),numsArray.end());
            reverse(numsArray.begin(),numsArray.end());
            for(auto x:numsArray)
                cout<<x;
        }
        else{
            cout<<-1;
        }
        if(T>0) cout<<"\n";

    }

    return 0;
}

