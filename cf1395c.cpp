/*⠄⠄⠄⠄⠄⠄⢀⣀⣤⣤⣤⣤⣤⣤⣤⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⢠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⡀⠄⠄⠄⠄
⠄⠄⠄⠄⠄⣰⣿⣿⡟⠻⣿⠟⠻⣿⣿⠛⢻⣿⡿⠻⣿⣿⣿⣦⡀⠄⠄
⠄⠄⠄⠄⣰⣿⡿⠋⠤⢤⡉⢰⡀⡈⢁⠄⠄⣙⡁⢀⡘⢿⢿⣿⣿⡄⠄
⠄⠄⠄⢠⣿⣿⠁⠄⠄⠄⢳⡀⢉⡀⣼⠄⠄⢨⠞⠉⠄⣀⡀⢿⣿⣿⠄
⠄⠄⣠⣼⣿⠇⠄⢀⡴⣒⢲⣷⠲⠇⠻⢧⣴⣿⢺⡙⣦⡌⠁⠄⣿⣿⣇
⠄⡞⠁⠄⡼⠄⠄⢹⡧⣉⠊⡟⠂⠄⠄⠄⠈⡇⣏⡷⣸⠁⠄⠄⢹⣿⢡
⠄⡇⠄⡀⠃⠄⠄⠄⠃⠩⠘⠂⢖⣛⠙⡦⠐⠛⠬⠕⠛⠃⠄⠄⠘⠃⢾
⠄⠳⣴⠃⠈⠚⠄⢠⠄⠄⠄⠄⠄⣹⣉⣀⣀⠄⠄⠄⡀⢢⣠⠄⠄⠄⡀
⠄⠄⡟⠄⠄⠄⠄⠘⢦⡤⠤⠖⠋⠉⠄⠄⠉⠉⠙⠲⡌⠃⠁⠄⠄⠄⣿
⠄⠄⡇⠄⠄⠄⢆⡄⢸⣇⣠⠖⠚⠩⠟⠉⠉⠙⠓⢢⡇⠄⠄⠄⠄⠄⣿
⠄⠄⡇⠄⠄⠄⠈⠄⠄⠙⢤⣤⠤⠖⠒⡒⠒⠒⠚⠁⠄⠐⡄⡀⠄⢀⡇
⠄⠄⢹⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠉⠁⠄⠄⠄⠄⠄⠄⠉⠠⢆⡞⠄
⠄⠄⠄⠱⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣠⠴⠋⠄⠄
⠄⠄⠄⠄⠈⠓⠒⠒⠒⠒⠒⠒⠛⠉⠉⠉⠉⠉⠉⠉⠉⠉⠄⠄*/
#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAiccelerator ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
const int N = 300;

int a[N], b[N], n, m;
set<int> qqai[2];

signed main()
{
    XinAiccelerator
    cin >> n >> m;
    qqai[1].insert(0);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    for (int i=1; i<=n; i++)
    {
        qqai[(i+1)&1].clear();
        for (int j=1; j<=m; j++)
            for (auto x: qqai[i&1])
                qqai[(i+1)&1].insert(x | (a[i]&b[j]));
    }
    cout << *qqai[(n+1)&1].begin() << '\n';
}