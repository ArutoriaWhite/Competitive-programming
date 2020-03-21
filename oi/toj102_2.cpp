#define _for(i,a,b) for(int i=(a),i<(b),i++)
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;


int main() {
  double a,b;
  char opr;
  cin>>a>>opr>>b;
  if(opr=='+') cout<<fixed<<setprecision(4)<<a<<" + "<<b<<" = "<<(a+b)<<endl;
  if(opr=='-') cout<<fixed<<setprecision(4)<<a<<" - "<<b<<" = "<<(a-b)<<endl;
  if(opr=='*') cout<<fixed<<setprecision(4)<<a<<" * "<<b<<" = "<<(a*b)<<endl;
  if(opr=='/') 
  {
      if(b!=0)  cout<<fixed<<setprecision(4)<<a<<" / "<<b<<" = "<<(a/b)<<endl;
      else cout<<"ERROR\n";
  }
}
