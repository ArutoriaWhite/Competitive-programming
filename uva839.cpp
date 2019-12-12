#include<iostream>
using namespace std;

int sagiri()
{
	int w1, d1, w2, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	if (w1==0) w1 = sagiri();
	if (w2==0) w2 = sagiri();
	if (w1<0 || w2<0 || (w1*d1!=w2*d2)) return -1;
	return w1+w2;
}

int main()
{
	bool fir=1;
	int T;
	cin >> T;
	while (T--)
	{
		if (fir) fir=0;
		else cout << '\n';
		if (sagiri()<0) cout << "NO\n";
		else cout << "YES\n";
	}
}


