#include<iostream>
using namespace std;
const int N=1e8;

int main()
{
	int a, b, t;
	while (cin >> a >> b)
	{
		t=0;
		while (b!=0)
		{
			if (t==0) cout << "[";
			else if (t==1) cout << ";";
			else cout << ",";			
			cout << a/b;
			int tmp=a;
			a=b;
			b=tmp%b;
			t++;			
		}
		cout << "]\n";
	}
}
