#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <random>
using namespace std;

long long power(long long a, long long n,long long m)
{
	long long tmp = a,ans = 1;
	while (n) {
		if (n&1) {
			ans = tmp*ans%m;
		}
		n /= 2;
		tmp = tmp*tmp%m;
	}
	return ans;
}

mt19937 mt(123);


int main() {

	long long p; while (cin>>p)
	{
		bool isPrime = true;
		_for (i, 0, 5) {
			if (power(mt()%(p-1)+1, p - 1,p) != 1) isPrime = false;
		}
		if (isPrime) cout << "質數\n";
		else cout << "非質數"<<"\n";

	}
	return 0;
}
