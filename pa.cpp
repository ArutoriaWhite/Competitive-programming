#include<algorithm>
#include<iostream>
using namespace std;

int ord[200];
inline bool cmp( char &a, char &b)
{
	return ord[a] < ord[b];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	for (int i=0; i<s.size(); i++)
		ord[s[i]] = i+1;
		
	string sagiri;
	cin >> sagiri;
	sort(sagiri.begin(),sagiri.end(),cmp);
	
	int q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		cout << sagiri[x-1] << '\n';
	}
}
