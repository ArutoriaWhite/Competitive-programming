#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define MAXINT (2147483647)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <set>

using namespace std;

void change(int pos, vector<string> &arr, int l) {
	pos = l - pos - 1;
	for(auto iter=arr.begin();iter!=arr.end();iter++){
		if ((*iter)[pos] == '1') (*iter)[pos] = '0';
		else (*iter)[pos] = '1';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	_for(_T,0,T)
	{
		int n, l; cin >> n >> l;
		vector<string> head;
		vector<string> devices;

		_for(i, 0, n) {
			string tmp; cin >> tmp;
			head.push_back(tmp);
		}
		_for(i, 0, n) {
			string tmp; cin >> tmp;
			devices.push_back(tmp);
		}
		sort(devices.begin(), devices.end());

		int minTime= MAXINT;
		//enum possible changes
		_for(i, 0, pow(2,l-1)) {
			int k=0;
			int tmpi = i;
			int t = 0;
			vector<string> tmpHead=head;

			//change value
			while (tmpi > 0) {
				if (tmpi & 1) {
					t++;
					change(k, tmpHead, l);
				}
				tmpi >>= 1; k++;
			}
			
			sort(tmpHead.begin(), tmpHead.end());
			if (tmpHead == devices)
				if (minTime == -1) minTime = t;
		}
	
		if (minTime == MAXINT)
			printf("Case #%d: IMPOSSIBLE\n", _T + 1);
		else
			printf("Case #%d: %d\n", _T + 1, minTime);
	}
	
	return 0;
}
