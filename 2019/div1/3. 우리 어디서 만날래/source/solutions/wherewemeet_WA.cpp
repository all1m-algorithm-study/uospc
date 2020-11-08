#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> tt;
int N, M, C, D;
int cnt = 0;
int vst[1003];
vector<tt> adj[1003];

void dfs(int u) {
	vst[u] = true;
	cnt += 1;
	for (auto& p : adj[u])
		if (!vst[p.first])
			dfs(p.first);

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M >> C;
	C -= 1;

	for (int i = 0, u, v, w; i < M; i++) {
		cin >> u >> v >> w;
		adj[v - 1].push_back({ u - 1,w });
	}
	cin >> D;
	fill(vst, vst + N, false);
	dfs(C);
	if (cnt == N) cout << 'Y' << '\n';
	else cout << 'N' << '\n';

}