#include<iostream>
using namespace std;
#define maxN 110

char arr[maxN][maxN];

int main()
{
	for( int i=0; i<maxN; i++)
	{
		for( int j=0; j<maxN; j++)
		{
			arr[i][j]=' ';
		}
	}
	
	string s;
	int i=0, mxlen=0;
	while (getline(cin,s))
	{
		int len = s.size();
		if (len>mxlen) mxlen = len;
		for( int j=0; j<len; j++)
		{
			arr[i][j]=s[j];
		}
		i++;
	}
	
	for( int j=0; j<mxlen; j++)
	{
		for( int k=i-1; k>=0; k--)
		{
			cout << arr[k][j];
		}
		cout << '\n';
	}
}
