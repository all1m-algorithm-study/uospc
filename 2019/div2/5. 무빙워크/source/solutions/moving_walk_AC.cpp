#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int>> adj[10000];
bool vst[10000];
int ans, D = 0;

void dfs(int u, int w) {
	vst[u] = true;
	for (auto& p : adj[u])
		if (!vst[p.first])
			dfs(p.first, w + p.second);
	if (D < w)
		D = w, ans = u;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back({ v - 1, w });
		adj[v - 1].push_back({ u - 1, w });
	}
	dfs(0, 0);
	fill(vst, vst + N, false);
	D = 0;
	dfs(ans, 0);
	cout << D;
}