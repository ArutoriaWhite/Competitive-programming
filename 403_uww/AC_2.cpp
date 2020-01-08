#include<iostream>
#include<vector>
using namespace std;

int LIS(vector<int>& s)
{
    if (s.size() == 0) return 0;
 
    vector<int> v;
    v.push_back(s[0]);
 
    for (int i = 1; i < s.size(); ++i)
    {
        int n = s[i];
 
        if (n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }
 
    return v.size();
}

vector<int> v;

int main()
{
	int n;
	cin >> n;
	for (int i=0,x; i<n; i++)
		cin >> x, v.push_back(x);
	cout << LIS(v) << '\n';
}
