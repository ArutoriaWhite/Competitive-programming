#include<iostream>
using namespace std;

int main()
{
	freopen("out.txt","w",stdout);
	int n, t=0;
	while (cin >> n)
	{
		if (n==0) return 0;
		int sum=0;
		for (int a=1; a<(n/3); a++)
			sum += (n-a+1)/2-a-1;
		cout << "Case " << ++t << ": " << sum << "\n";
	}
}
