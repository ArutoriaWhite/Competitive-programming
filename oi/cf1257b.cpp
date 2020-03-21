#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--)
	{
		int x, y;
		cin >> x >> y;
		if (x>=4)
			cout << "Yes\n";
		else if ((x==2||x==3)&&(y<4))
			cout << "Yes\n";
		else if (x==y)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}

