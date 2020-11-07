#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> tt;
int N, M, C, D;
int dist[1003];
vector<tt> adj[1003];

int dijstra(int s) {
	fill(dist, dist + N, 1e9);
	dist[s] = 0;
	priority_queue<tt> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (auto v : adj[cur]) {
			int next = v.first;
			int nextCost = cost + v.second;
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}
	return dist[C];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M >> C;
	C -= 1;

	for (int i = 0, u, v, w; i < M; i++) {
		cin >> u >> v >> w;
		adj[u - 1].push_back({ v - 1,w });
	}
	cin >> D;
	
	int ans = true;
	for (int i = 0; i < N; i++) {
		if (dijstra(i) > D) ans = false;
	}

	if (ans) cout << 'Y' << '\n';
	else cout << 'N' << '\n';
}
