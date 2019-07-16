#define _for(i,a,b) for(int i=(a);i<b;i++)
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int arr[n];
    _for(i,0,n)
        cin>>arr[i];
        
    int T;cin>>T;
    while(T--){
        int i1,i2;
        cin>>i1>>i2;
        i1--;i2--;
        if(abs(i2-i1)>8){
            cout<<"I QUIT!"<<endl;
            goto IQUIT;
        }
        else{
            int tmp=arr[i1];
            arr[i1]=arr[i2];
            arr[i2]=tmp;
        }
    }
    cout<<"SORTED!"<<endl;
    
    IQUIT:
    
        _for(i,0,n){
        //cout<<"n:"<<n<<endl;
        if(i+1==n)
            cout<<arr[i]<<endl;
        else cout<<arr[i]<<' ';
    }
    return 0;
}
