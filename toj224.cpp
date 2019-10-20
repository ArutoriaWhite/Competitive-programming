#define _for(i,a,b) for(int i=(a);i<b;++i)
#include <iostream> 
using namespace std;

int main(){
  int a,b;cin>>a>>b;
  if(a>b){
    int tmp=a;
    a=b;
    b=tmp;
  }

  long long sum=1;
  _for(i,a,b+1){
    sum*=i;
  }
  cout<<sum<<endl;
  
}
