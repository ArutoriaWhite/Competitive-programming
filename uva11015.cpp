#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <numeric>

using namespace std;

typedef pair<int, int> pii;
vector<vector<pii>> adjList;
vector<int> dis;

void bellmanFord(int start,int n) {
	dis.resize(n);
	for (auto iter = dis.begin(); iter != dis.end(); iter++) (*iter) = 0x3f3f3f;
	dis[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		for (auto next : adjList[now]) {
			if (dis[next.first] > dis[now] + next.first) {
				q.push(next.first);
				dis[next.first] = dis[now] + next.first;
			}
		}
	}
}
int main() {
	vector<string> names;

	int N, M; cin >> N >> M;
	_for(i, 1, N + 1) {
		string cinTmp; cin >> cinTmp;
		names.push_back(cinTmp);
	}
	adjList.resize(22);
	_for(i, 0, M) {
		int n1, n2, d; cin >> n1 >> n2 >> d;
		n1--; n2--;
		adjList[n1].push_back(pii(n2,d));
		adjList[n2].push_back(pii(n1, d));
	}
	int min=0x3f3f3f;
	_for(i, 0, adjList.size()) {
		bellmanFord(i, adjList.size());
		int disSum = accumulate(dis.begin(), dis.end(), 0);
		if (disSum > min) min = disSum;
	}
	cout << names[min + 1] << "\n";
	return 0;
}
