#include <bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int N = 3e5+10, LOG = 64;

long long k;
int qwq[N], ouo[N], pos[N][LOG], n, lgk;
int *card, *tmp;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	card = qwq, tmp = ouo;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> card[i];
	for (int i=1; i<=n; i++) cin >> pos[i][0];
	cin >> k, lgk = __lg(k)+1;
	for (int j=1; j<=lgk; j++)
		for (int i=1; i<=n; i++)
			pos[i][j] = pos[ pos[i][j-1] ][j-1];
	while (k>0)
	{
		int s = __lg(lowbit(k));
		k -= lowbit(k);
		for (int i=1; i<=n; i++)
			tmp[pos[i][s]] = card[i];
		swap(card,tmp);
	}

	for (int i=1; i<=n; i++)
		cout << card[i] << "\n "[i+1<=n];
}
