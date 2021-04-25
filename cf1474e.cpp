#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
/*
a lenght N permutation P, make i = P[i] in min cost with operation:
// sort P
select i, j such that p[i]=j and swap(i,j)
// at least one element must back to right position after swap
cost (j-i)^2 // dis^2
operations always less than n

find a P, maximize the min cost of P
*/