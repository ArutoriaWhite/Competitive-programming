#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

 int n, res = 1;
 string s;

 int main()
 {
     cin >> n >> s;
     for (int i=0; i<n; i++)
     {
         res *= i+1;
         int cnt = 0;
         for (int j=0; j<=i; j++)
            if (s[j] == s[i]) cnt++;
        if (cnt*2 > )
        res /= cnt;
     }
     cout << res << '\n';
 }