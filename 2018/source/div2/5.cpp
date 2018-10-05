#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int min_cost[101][101];
	int bead[101];
	int sum[101];
	int T;
	cin >> T;
	while (T--) {
		memset(min_cost, 0, sizeof(min_cost));
		memset(sum, 0, sizeof(sum));
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
			cin >> bead[i];
		for (int i = 1; i <= k; i++)
			sum[i] = sum[i - 1] + bead[i];
		for (int distance = 1; distance < k; distance++)
			for (int r = 1; r + distance <= k; r++) {
				int c = r + distance;
				min_cost[r][c] = min_cost[r][r] + min_cost[r + 1][c] + sum[c] - sum[r - 1];
				for (int i = r + 1; i < c; i++) {
					int tmp = min_cost[r][i] + min_cost[i + 1][c] + sum[c] - sum[r - 1];
					if (min_cost[r][c] > tmp) min_cost[r][c] = tmp;
				}
			}
		printf("%d\n", min_cost[1][k]);
	}
	return 0;
}