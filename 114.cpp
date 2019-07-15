/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#define _for(i,a,b) for(int i=(a) ;i<(b) ;i++)
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int arr[6][5];
    bool isLine=false;
    
    _for(y,0,5){
        _for(x,0,6){
            cin>>arr[y][x];
        }
    }
    
    _for(_y,0,5){
        int lastX=-1,lastY,cntr=1;
        _for(_x,0,6){
            
            if(lastX!=-1){
                if(arr[lastY][lastX]==arr[_y][_x])
                    cntr++;
                else
                    cntr=0;
            }
            if(cntr>=3){
                isLine=true;
                goto doubleBreak;
            }
            lastX=_x;lastY=_y;

        }
    }

    doubleBreak:
    
    if(!isLine){
        _for(_x_,0,6){
        int lastX=-1,lastY,cntr=1;
        _for(_y_,0,5){
            
            if(lastX!=-1){
                if(arr[lastY][lastX]==arr[_y_][_x_])
                    cntr++;
                else
                    cntr=0;
            }
            if(cntr>=3){
                isLine=true;
                goto doubleBreak;
            }
            lastX=_x_;lastY=_y_;

        }
    }

    }
    
    if(isLine) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
