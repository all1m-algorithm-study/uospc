#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> point;
int N, T;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	long long ans = 0;
	cin >> N >> T;

	while (T--) {
		vector<int> rate(N);
		for (int i = 0; i < N; i++)
			cin >> rate[i];

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
	cout << ans;
}