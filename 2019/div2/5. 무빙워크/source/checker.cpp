#include "testlib.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int>> adj[10000];
bool vst[10000];
int cur, D = 0;

void dfs(int u, int w) {
	vst[u] = true;
	for (auto& p : adj[u])
		if (!vst[p.first])
			dfs(p.first, w + p.second);
	if (D < w) D = w, cur = u;
}

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	int N = inf.readInt();
	inf.readEoln();

	for (int i = 0; i < N - 1; i++) {
		int u = inf.readInt();
		inf.readSpace();
		int v = inf.readInt();
		inf.readSpace();
		int w = inf.readInt();
		inf.readEoln();
		cin >> u >> v >> w;
		adj[u - 1].push_back({ v - 1, w });
		adj[v - 1].push_back({ u - 1, w });
	}
	dfs(0, 0);
	fill(vst, vst + N, false);
	D = 0;
	dfs(cur, 0);

	int A = ouf.readInt();

	if (A != D)
		quitf(_wa, "Wrong Answer");

	quitf(_ok, "Correct!");
}