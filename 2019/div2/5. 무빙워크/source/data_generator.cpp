#include "testlib.h"

using namespace std;
typedef pair<int, int> tt;
int p[100000];
int edges[100000000];

int find(int u) {
	if (p[u] < 0) return u;
	return p[u] = find(p[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (p[u] < p[v]) p[u] += p[v], p[v] = u;
	else p[v] += p[u], p[u] = v;
	return true;
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int l = atoi(argv[1]);
	int r = atoi(argv[2]);
	int a = atoi(argv[3]);
	int b = atoi(argv[4]);


	int N = rnd.next(l, r);
	fill(p, p + N, -1);

	cout << N << endl;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		edges[i * N + j] = rnd.next(a, b);
	
	int cnt = 0;
	for (auto t : rnd.perm(N* N)) {
		int u = t / N;
		int v = t % N;
		if (merge(u, v)) {
			cnt += 1;
			cout << u + 1 << " " << v + 1 << " " << edges[t] << endl;
		}
		if (cnt == N - 1) break;
	}

	return 0;
}