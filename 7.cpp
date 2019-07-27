#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{    
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while (T--)
	{
		vector<int> arr;
		//arr.reserve(23);
		int n; cin >> n;
		_for(i, 0, n + 1) {
			int tmp; cin >> tmp;
			arr.push_back(tmp);
		}
		
		while (arr.size() > 1) {
			vector<int> tmp;
			tmp.reserve(23);
			_for(i, 0, arr.size() - 1)
				tmp.emplace_back(arr[i + 1] - arr[i]);
			arr = tmp; 
		}
		cout << arr[0]<<endl;
	}

	return 0;
}

