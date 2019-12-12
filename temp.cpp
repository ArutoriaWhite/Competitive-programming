#include<bits/stdc++.h>

using namespace std;
bool can[10000000];
int data[10000000];

int main() {
	int tt;
	scanf("%d",&tt);
	for(int mm=0; mm<tt; mm++){
		memset(can,0,sizeof(can));
		int studentNum;
		scanf("%d",&studentNum);

		for(int m=0; m<studentNum; m++) {
			int ttftt;
			scanf("%d",&ttftt);
			data[m] = ttftt;
		}
		for(int i=0; i<studentNum; i++) {
			for(int j=i+1; j<studentNum; j++) {
				if (data[i]==0 || data[j]==0) continue;
				can[data[i]+data[j]]=1;
			}
		}

		int ko;
		scanf("%d",&ko);
		for(int m=0; m<ko; m++) {
			int f;
			scanf("%d",&f);
			if(can[f] == 1) {
				printf("Good!\n");
			} else {
				printf("So Bad!\n");
			}
		}
	}
	return 0;
}
