#define _for(i,a,b) for(int i=(a);i<b;++i)
#include <iostream> 
#include <stdio.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  _for(i,1,n+1){
    _for(j,1,m+1){
      printf("%d*%d=%d ",i,j,i*j);
    }
    cout<<endl;
  }
  return 0;
}
