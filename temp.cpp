#include<iostream>
#include<cstring>
using namespace std;

int ouo[3];
int main()
{
	memset(ouo,0x7f,sizeof(ouo));
	for (int i=0; i<3; i++)
		cout << ouo[i] << ' ';
}
