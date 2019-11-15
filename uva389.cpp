#include<iostream>
using namespace std;

int w()
{
	int w1, d1, w2, d2;	
	cin >> w1 >> d1 >> w2 >> d2;
	if (w1==0) w1 = w();
	if (w2==0) w2 = w();
	if (w1==-1 || w2==-1 || w1*d1!=w2*d2) return -1;
	return w1 + w2;
}

int main() {
	bool fir=1;
	int T;
	cin >> T;
	while (T--)
	{
		int k=w();
		if (fir) fir=0;
		else cout << '\n';
		if (k==-1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}

