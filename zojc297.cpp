#include<iostream>
using namespace std;
#define lowbit(x) (x&-x)

string hit[10][10];

int main()
{
	int mxa=0;
	for( int i=0; i<9; i++)
	{
		int a;
		cin >> a;
		if (a>mxa) mxa=a;
		for( int j=0; j<a; j++)
		{
			cin >> hit[i][j];
		}
	}
		
	int b;
	cin >> b;
	int o=0, s=0, base=0;
	
	for( int j=0; j<mxa&&(o<b); j++)
	{
		for( int i=0; i<9&&(o<b); i++)
		{
			if (hit[i][j]=="1B")
			{
				base<<=1, base++;
			}
			else if (hit[i][j]=="2B")
			{
				base<<=1, base++;
				base<<=1;
			}
			else if (hit[i][j]=="3B")
			{
				base<<=1, base++;
				base<<=2;
			}
			else if (hit[i][j]=="HR")
			{
				base<<=1, base++;
				base<<=4;
			}
			if (base>7)
			{
				int tmp=base;
				while (tmp>0)
				{
					if (lowbit(tmp)>7) s++;
					tmp-=lowbit(tmp);
				}
				base -= ((base>>3)<<3);
			}
		
			if (hit[i][j]=="FO"||hit[i][j]=="GO"||hit[i][j]=="SO")
			{
				o++;
				if (o%3==0)
				{
					base=0;
				}
			}
		}
	}
	cout << s << '\n';
	
}
