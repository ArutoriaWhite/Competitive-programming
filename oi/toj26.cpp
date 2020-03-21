#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

string s="";

int dpArr[3000][3000] = { 0 };

int dp(int i,int edge) {
	if (dpArr[i][edge] == 0) {

		//end
		if (i == edge) dpArr[i][edge] = 1;
		else if (i + 1 == edge) dpArr[i][edge] = (s[i] == s[edge]) ? 2 : 1;

		else {
			bool isPaired = false;
			int stepCntr = 0;
			//find pair with i
			for (int j = edge; j > i; j--) {
				if (s[j] == s[i]) {
					if (i + 1 == j) {
						dpArr[i][edge] = max(dp(i + 1, edge), 2); // ....cc... 如果遞迴到下一次算會多算1
						return dpArr[i][edge];
					}
					isPaired = true;
					stepCntr++;
					break;
				}
			}
			if (isPaired)	dpArr[i][edge] = max(dp(i + 1, edge-stepCntr) + 2, dp(i + 1, edge));
			else			dpArr[i][edge] = max(1, dp(i + 1, edge));
		}
	}

	return dpArr[i][edge];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--)
	{
		memset(dpArr, 0, sizeof(dpArr));
		cin >> s;
		cout << dp(0, s.length()-1);
		if (T > 0) cout << "\n";
	}
	return 0;
}
