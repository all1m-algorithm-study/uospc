#include <iostream>
#include <algorithm>
using namespace std;
int N;
int P[1003];
int dp1[1003][1003];
int dp2[1003];

int main()
{
	cin >> N;
	
	// L = 1
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		fill(dp1[i], dp1[i] + N, 1e9);
		dp1[i][i] = 3;
	}

	// L = 2
	for (int i = 0; i < N - 1; i++) {
		if (P[i] == P[i + 1])
			dp1[i][i + 1] = 3;
	}

	// L = 3, 4
	for (int k = 2; k <= 3; k++) {
		for (int i = 0, j; i < N - k; i++) {
			j = i + k;
			if (P[i] == P[j] && dp1[i + 1][j - 1] == 3) {
				if (P[i] < P[i + 1]) dp1[i][j] = 1;
				else if (P[i] > P[i + 1]) dp1[i][j] = 2;
				else dp1[i][j] = 3;
			}
		}
	}

	// L > 4
	for (int k = 4; k < N; k++) {
		for (int i = 0, j; i < N - k; i++) {
			j = i + k;
			if (P[i] == P[j]) {
				if (dp1[i + 1][j - 1] == 1 && P[i] < P[i + 1])
					dp1[i][j] = 1;
				else if (dp1[i + 1][j - 1] == 2 && P[i] > P[i + 1])
					dp1[i][j] = 2;
				else if (dp1[i + 1][j - 1] <= 3)
					dp1[i][j] = 3;
			}
		}
	}

	dp2[0] = 3;
	for (int i = 1; i < N; i++) {
		dp2[i] = dp2[i - 1] + 3;
		for (int j = 0; j < i; j++) {
			if (P[i] == P[j]) {
				if (j == 0) dp2[i] = min(dp2[i], dp1[j][i]);
				else dp2[i] = min(dp2[i], dp2[j-1] + dp1[j][i]);
			}
		}
	}

	cout << dp2[N - 1] << endl;
}