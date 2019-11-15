#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	while (cin >> s)
	{
		if (s=="0") return 0;
		int res=0;
		for (int i=0; i<s.size(); i++)
			res*=10, res+=s[i]-'0', res%=11;
		if (res==0) cout << s << " is a multiple of 11.\n";
		else cout <<  s << " is not a multiple of 11.\n";
	}
	return 0;
}

