#define _CRT_SECURE_NO_WARNINGS
#define _for(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define TIME 25
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <map>
#include <tuple>
using namespace std;


//0 prince win
//1 princess win
//2 referee win
map<pair<int, int>, int> whoWin = {
	{{2,2},2},{{2,0},1},{{2,5},0},
	{{0,2},0},{{0,0},2},{{0,5},1},
	{{5,2},1},{{5,0},0},{{5,5},2}
};
string arr[] = { "The prince wins." ,"The princess wins." ,"The referee wins." };
int main() {
	int T; cin >> T;
	while (T--)
	{
		int prince, princess; cin >> prince >> princess;
		cout << arr[whoWin[*(new pair<int,int>(prince,princess))]]<<endl;

	}
		return 0;
}
