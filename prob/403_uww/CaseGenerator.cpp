#include <iostream>
#include <unordered_set>
#include <random>
using namespace std;

unordered_set<int> s;

int main()
{
	freopen("c5.txt","w",stdout);
	
	int n = 988886, mn = -1e6+100, mx=1e6-100;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distri(mn,mx);
	
	cout << n << '\n';
	while (n>0)
	{
		int r = distri(gen);
		if (s.find(r)==s.end())
		{
			s.insert(r);
			n--;
			cout << r << ' ';
		}
		cout << '\n';
	}
}
