#define _CRT_SECURE_NO_WARNINGS
#define _for(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define TIME 25
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int stoneAmnt, gashTypeAmnt, rest,usedStone=0;
	cin >> stoneAmnt >> gashTypeAmnt >> rest;
	_for(i, 0, gashTypeAmnt) {
		int a, b; cin >> a >> b;
		usedStone += a * b;
	}
	usedStone += stoneAmnt;
	usedStone -= rest;
	cout << usedStone / 4<<endl;

	return 0;
}
