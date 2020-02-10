#include <iostream>
#define ton(c) (c-'0')
using namespace std;

int type[10][5] = { {1,3,0,3,1}, {0,1,0,1,0}, {1,1,1,2,1}, {1,1,1,1,1},
					{0,3,1,1,0}, {1,2,1,1,1}, {1,2,1,3,1}, {1,1,0,1,0},	
					{1,3,1,3,1}, {1,3,1,1,1}}, sz;
string ver[] = {"  "," |","| ","||"}, hor = " -", sn;

inline void print_ver (int n)
{
	cout << ver[n][0];
	for (int j=0; j<sz; j++) cout << ' ';
	cout << ver[n][1];
}
inline void print_hor (int n)
{
	cout << ' ';
	for (int i=0; i<sz; i++) cout << hor[n];
	cout << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> sz >> sn && (sz!=0 || sn!="0"))
	{
		for (int j=0; j<5; j++)
			if (j&1)
				for (int i=0; i<sz; i++)
					for (int k=0,len=sn.size(); k<len; k++)
						print_ver(type[sn[k]-'0'][j]), cout << "\n "[k+1<len];
			else
				for (int i=0,len=sn.size(); i<len; i++)
					print_hor(type[sn[i]-'0'][j]), cout << "\n "[i+1<len];
		cout << '\n';
	}
}
