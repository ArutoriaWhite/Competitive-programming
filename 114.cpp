#define _CRT_SECURE_NO_WARNINGS
#define _for(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define TIME 25
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

struct Vec2
{
public:
	int x=0, y=0;
	Vec2(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Vec2() {};
	Vec2  operator +(const Vec2 &arg) {
		Vec2 tmp(x + arg.x, y + arg.y);
		return  tmp;
	}
	bool const operator < (const Vec2 &b) const {
		return((y < b.y) || ( (y == b.y) && (x < b.x) ) );
	}
	bool const operator >(const Vec2 &b) const {
		return((y > b.y) || ((y == b.y) && (x > b.x)));
	}
	bool const operator ==(const Vec2 &b) const {
		return(x == b.x&&y == b.y);
	}
}; 

map<Vec2, int> arr; 

int main() { 
	_for(y, 0, 5) {
		_for(x, 0, 5) {
			int tmp; cin >> tmp;
			Vec2 vec(x, y);
			arr[vec] = tmp;
		}
	}
	_for(y, 0, 5) {
		_for(x, 0, 5) {
			
		}
	}
	return 0;
}
