#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int l = atoi(argv[1]);
	int r = atoi(argv[2]);
	int a = atoi(argv[3]);
	int b = atoi(argv[4]);

	int N = rnd.next(a, b);
	int T = rnd.next(1, 10);

	printf("%d %d\n", N, T);

	while (T--) {
		for (int i = 0; i < N - 1; i++) {
			cout << rnd.next(l, r) << " ";
		}
		cout << rnd.next(l, r) << endl;
	}
	return 0;
}