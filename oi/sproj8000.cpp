#include<iostream>
#include<algorithm>
using namespace std;

int yamete[3];

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<3; j++)
			cin >> yamete[j];
		sort(yamete,yamete+3);
		if (yamete[0] + yamete[1] <= yamete[2])
			cout << "Normal Guy\n";
		else
			cout << "Illuminati Confirmed\n";
	}
}
