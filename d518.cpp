
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> mp;
int n, cnt;
string s;

inline void init ()
{
    cnt = 1;
    mp.clear();
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n)
    {
        init();
        for (int i=0; i<n; i++)
        {
            cin >> s;
            if (mp.find(s)==mp.end())
                cout << "New! " << (mp[s]=cnt++) << '\n';
            else
                cout << "Old! " << mp[s] << '\n';
        }
    }
}