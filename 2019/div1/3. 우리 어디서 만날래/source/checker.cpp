#include "testlib.h"
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> tt;
int N, M, C, D;
int dist[1003];
vector<tt> adj[1003];

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	int N = inf.readInt(); inf.readSpace();
	int M = inf.readInt(); inf.readSpace();
	int C = inf.readInt(); inf.readEoln();
	C -= 1;

	for (int i = 0, u, v, w; i < M; i++) {
		u = inf.readInt(); inf.readSpace();
		v = inf.readInt(); inf.readSpace();
		w = inf.readInt(); inf.readEoln();
		adj[v - 1].push_back({ u - 1,w });
	}
	D = inf.readInt(); inf.readEoln();
	fill(dist, dist + N, 1e9);

	dist[C] = 0;
	priority_queue<tt> pq;
	pq.push({ 0, C });
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
	char ans = 'Y';
	for (int i = 0; i < N; i++) {
		if (dist[i] > D) ans = 'N';
	}

	char A = ouf.readChar();

	if (A != ans)
		quitf(_wa, "Wrong Answer");

	quitf(_ok, "Correct!");
}