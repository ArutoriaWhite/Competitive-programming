#include<iostream>
#include<vector>
using namespace std;

string s;
vector<string> res;
vector<string> tmp;

void gen (int i)
{
    if (i==0)
    {
        res.clear();
        res.push_back({s[0]});
        return;
    }
    gen(i-1);
    tmp.clear();
    for (auto x: res)
    {
        for (int j=0; j<=i; j++)
        {
            string y;
            for (int k=0; k<j; k++)
                y += x[k];
            y += s[i];
            for (int k=j; k<i; k++)
                y += x[k];
            tmp.push_back(y);
        }
    }
    res.clear();
    for (auto x: tmp)
        res.push_back(x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool fir=1;
    while (cin >> s)
    {
        if (fir) fir=0;
        else cout << '\n';
        gen(s.size()-1);
        for (auto x: res)
            cout << x << '\n';
    }
}