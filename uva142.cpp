#include <bits/stdc++.h>
#define DE cout << " ::"
using namespace std;

struct rec {int l,u,r,d; char id;};
struct icon {int x, y, id;};
vector<rec> recs;
vector<icon> icons;
vector<int> ans;
char rid='A', opr, res;
int iid = 1, firm = 1, x, y, z, w;

inline bool inrec (int x, int y, const rec &r)
{
	return r.l<=x&&x<=r.r && r.u<=y&&y<=r.d;
}

inline bool any_rec (int x, int y)
{
	for (int i=recs.size()-1; i>=0; i--)
		if (inrec(x,y,recs[i])) 
		{
			res=recs[i].id;
			return 1;
		}
	return 0;
}
inline void find_icon (int x, int y)
{
	int min_dis = 1e9, d;
	ans.clear();
	for (auto &ic: icons)
	{
		if (ic.x<0 || ic.y<0) continue;
		d = pow(ic.x-x,2) + pow(ic.y-y,2);
		if (d< min_dis)
			ans.clear(), ans.push_back(ic.id), min_dis=d;
		else if (d==min_dis)
			ans.push_back(ic.id);
	}
	for (auto a: ans)
		cout << setw(3) << a;
	cout << '\n';
}
inline void clear_icon ()
{
	for (auto &ic: icons)
		for (auto &r: recs)
			if (inrec(ic.x,ic.y,r))
				 ic.x = ic.y = -1;
}
int main()
{
	while (cin >> opr && opr!='#')
	{
		if (opr == 'I')
			cin >> x >> y, icons.push_back({x,y,iid++});
		else if (opr == 'R')
			cin >> x >> y >> z >> w, recs.push_back({x,y,z,w,rid++});
		else if (opr == 'M')
		{
			cin >> x >> y;
			if (firm) clear_icon();
			if (any_rec(x,y)) cout << res << '\n';
			else find_icon(x,y);
		}
	}
}

