#include<bits/stdc++.h>
using namespace std;

vector<int>a,q;

int main(){
	int n,t;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	int len=a.size();
	sort(a.begin(), a.begin()+1);

	cin>>t;
	for(int i=0;i<n;i++){
		cin>>q[i];
	
		int l=0,r=n-1;
		while(l<r){
			int m=(l+r)/2;
			if(a[m]>=q[i])r=m;
			else l=m+1;
		}
		
		if(a[r]==q[i])
			cout<<"Š³A\n";
		else 
			cout<<"šSŠ³\n"<<a[r]<<"\n";	
			
			
	}
}
