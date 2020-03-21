#include<iostream>
#include<queue>
using namespace std;

priority_queue< int, vector<int>, greater<int> > pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, opr, x; 
    cin >> T;
    while (T--)
    {
        cin >> opr;
        if (opr == 1)
        {
            cin >> x;
            pq.push(x);
        }
        else
        {
            if (pq.empty()) cout << "empty!\n";
            else cout << pq.top() << '\n', pq.pop();
        }
    }
}