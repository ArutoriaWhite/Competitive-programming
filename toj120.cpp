#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
using namespace std;

int main() {
  int n;cin>>n;
  long  arr[n],s[n];
  arr[0]=0;
  _for(i,1,n+1){
    cin>>arr[i];
    s[i]=s[i-1]+arr[i];
  }
	
  int T;cin>>T;
  while(T--){
    int i1,i2;cin>>i1>>i2;
    if(i1>i2){
      int tmp=i1;
      i1=i2;
      i2=tmp;
    }
    i1--;
    cout<<s[i2]-s[i1]<<endl;
  }
}
