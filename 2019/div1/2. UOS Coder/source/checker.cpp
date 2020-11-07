#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> point;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	long long int ans = 0;
	int N = inf.readInt();
	inf.readSpace();
	int T = inf.readInt();
	inf.readEoln();

	while (T--) {
		vector<int> rate(N);
		for (int i = 0; i < N - 1; i++) {
			rate[i] = inf.readInt();
			inf.readSpace();
		}
		rate[N - 1] = inf.readInt();
		inf.readEoln();

		vector<point> v;
		for (int i = 0; i < N - 1; i++) {
			int a = rate[i];
			int b = rate[i + 1];
			if (a <= b) {
				v.push_back(point(a, 1));
				v.push_back(point(b, -1));
			}
		}
		int cnt = 0;
		int s = 0;
		sort(v.begin(), v.end());
		for (point i : v) {
			cnt += i.second;
			if (cnt > s)
				s = cnt;
		}
		ans += 10 * s;
	}

	long long int A = ouf.readLong();

	if (A != ans)
		quitf(_wa, "Wrong Answe");

	quitf(_ok, "Correct!");
}