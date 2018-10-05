#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int T;
	int area_x[50];
	int area_y[50];
	int area_r[50];
	cin >> T;
	while (T--) {
		int x1, y1, x2, y2;
		int n, count = 0;
		cin >> x1 >> y1 >> x2 >> y2; 
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> area_x[i] >> area_y[i] >> area_r[i];
		for (int i = 0; i < n; i++) {
			bool a = (double)area_r[i] > sqrt(pow(x1 - area_x[i], 2) + pow(y1 - area_y[i], 2));
			bool b = (double)area_r[i] > sqrt(pow(x2 - area_x[i], 2) + pow(y2 - area_y[i], 2));
			if (a != b)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}