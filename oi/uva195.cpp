#include <iostream>
#include <algorithm>
#define DE cout << " ::"
using namespace std;

inline char lower (const char &c)
{
    if ('a'<=c&&c<='z') return c;
    else return c-'A'+'a';
}
inline bool cmp (const char &x, const char &y)
{
    if (lower(x) != lower(y)) return lower(x)<lower(y);
    else return x<y;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), cmp);
        do cout << s << '\n';
        while (next_permutation(s.begin(), s.end(), cmp));
    }
}
/*
2
za
az
*/