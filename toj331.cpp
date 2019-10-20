#define _for(i,a,b) for(int i=(a);i<b;++i)
#include <iostream> 
#include <stdio.h>
#include <string>
using namespace std;

long long Len( string &s ){
  long long zeroCount=0,len=s.size();
  _for(i,0,len){
    if(s[i]=='0') zeroCount++;
  }
  len-=zeroCount;
  return len;

}

int main(){
  string a,b;cin>>a>>b;
  cout<<Len(a)*Len(b)<<endl;
  return 0;
}
