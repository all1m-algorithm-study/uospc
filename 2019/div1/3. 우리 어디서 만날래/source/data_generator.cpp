#include "testlib.h"
#include <fstream>

using namespace std;
typedef pair<int, int> tt;
int edges[100000000];

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int l1 = atoi(argv[1]);
	int r1 = atoi(argv[2]);
	int l2 = atoi(argv[3]);
	int r2 = atoi(argv[4]);
	int d = atoi(argv[5]);
	
	//ofstream out("testcase3");

	int N = rnd.next(l1, r1);
	int M = rnd.next(l2, r2);
	int C = rnd.next(1, N);

	cout << N << " " << M << " " << C << endl;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		edges[i * N + j] = rnd.next(1, 100);

	int cnt = 0;
	for (auto t : rnd.perm(N * N)) {
		int u = t / N;
		int v = t % N;
		if (u == v) continue;
		else {
			cnt += 1;
			cout << u + 1 << " " << v + 1 << " " << edges[t] << endl;
		}
		if (cnt == M) break;
	}

	cout << d << endl;

	return 0;
}