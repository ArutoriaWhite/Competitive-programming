#define _for(i,a,b) for(int i=(a);i<b;++i)
#include <iostream> 
#include <stdio.h>
#include <string>
#include <map>
#include <tuple>
using namespace std;


map<int,long long> G_value;

long long G(int x){
  if(x==0) return 0;
  if(x==1) return 1;
  if(! G_value.count(x))
    G_value[x]=(G(x-2)-G(x-1));
  
  return G_value[x];
}

int main(){
  int T;cin>>T;
  while(T--){
    int x; cin>>x;
    printf("G(%d) = %lld\n",x,G(x));

  }
}
