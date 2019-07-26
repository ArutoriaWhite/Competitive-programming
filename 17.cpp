#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

string alphabetArr[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

int main ()
{
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin>>n){
        vector<string> toOutput;
        int blankAmnt=n-1;
        int alphabet=1;
        
        while(blankAmnt>0){
            string tmp;
            _for(i,0,blankAmnt) tmp+=" ";
            _for(i,0,alphabet) tmp+=alphabetArr[i];
            for(int i=alphabet-2;i<=0;i--) tmp+=alphabetArr[i];
            tmp+="\n";
            toOutput.push_back(tmp);
            blankAmnt--;
        }
        for(auto x: toOutput){
            cout<<x;
        }


    }

    return 0;
}
