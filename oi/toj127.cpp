#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


int toNum(char c){
    return (int)(c-65);
}
char toChar(int n){
    return (char(n+65));
}

int main() {
    
    int offset; cin>>offset;
    string s; cin>>s;
    int n=s.size();
    int nums[n];
    
    _for(i,0,n){
        nums[i]=toNum(s[i])-offset;
    }
    
    _for(i,0,n){
        while(nums[i]<0){
            nums[i]+=26;
        }
        while(nums[i]>25){
            nums[i]-=26;
        }
    }
    
    _for(i,0,n){
        s[i]=toChar(nums[i]);
        //cout<<nums[i];
        cout<<s[i];
    }
    
    cout<<endl;

    return 0;

  
}
