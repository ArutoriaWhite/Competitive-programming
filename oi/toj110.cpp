#define _CRT_SECURE_NO_WARNINGS
#define _for(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define N 4
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--)
	{
		int i, j, n, blank, star;
		cin >> n;

		blank = n - 1;
		star = 1;
		_for(i, 0, n - 3) {
			_for(j, 0, blank)
				cout << ' ';
			_for(j, 0, star)
				cout << '*';
			blank--;
			star += 2;
			cout << endl;
		}

		_for(i, 0, 2 * n - 1)
			cout << '*';
		cout << endl << ' ';
		_for(i, 0, 2 * n - 3)
			cout << '*';
		cout << endl;
		_for(i, 0, 2 * n - 1)
			cout << '*';
		cout << endl;

		blank = 3;
		star = 2 * n - 7;
		int tmp = n - 3;
		_for(i, 0, tmp) {
			_for(j, 0, blank)
				cout << ' ';
			_for(j, 0, star)
				cout << '*';
			blank++;
			star -= 2;
			cout << endl;
		}
	}
return 0;

}
