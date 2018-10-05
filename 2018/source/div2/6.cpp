#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int room[102][102];
bool visited[102][102];

int BFS(queue<pair<int, int>> q1) {
	int count = -1;
	queue<pair<int, int>> q2;
	while (!q1.empty() || !q2.empty()) {

		if(!q1.empty()) count++;
		while (!q1.empty()) {		
			int now_x = q1.front().first;
			int now_y = q1.front().second;
			q1.pop();
			for (int i = -1; i <= 1; i += 2) {
				if (!visited[now_x + i][now_y] && !room[now_x + i][now_y]) {
					visited[now_x + i][now_y] = true;
					room[now_x + i][now_y] = 1;
					q2.push(pair<int, int>(now_x + i, now_y));
				}
				if (!visited[now_x][now_y + i] && !room[now_x][now_y + i]) {
					visited[now_x][now_y + i] = true;
					room[now_x][now_y + i] = 1;
					q2.push(pair<int, int>(now_x, now_y + i));
				}
			}
		}

		if (!q2.empty()) count++;
		while (!q2.empty()) {
			int now_x = q2.front().first;
			int now_y = q2.front().second;
			q2.pop();
			for (int i = -1; i <= 1; i += 2) {
				if (!visited[now_x + i][now_y] && !room[now_x + i][now_y]) {
					visited[now_x + i][now_y] = true;
					room[now_x + i][now_y] = 1;
					q1.push(pair<int, int>(now_x + i, now_y));
				}
				if (!visited[now_x][now_y + i] && !room[now_x][now_y + i]) {
					visited[now_x][now_y + i] = true;
					room[now_x][now_y + i] = 1;
					q1.push(pair<int, int>(now_x, now_y + i));
				}
			}
		}

	}
	
	return count;
}

int main(void) {
	int m, n, count;
	cin >> m >> n;
	memset(room, -1, sizeof(room));
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int input;
			cin >> input;
			room[i][j] = input;
		}
	queue<pair<int, int>> q;
	bool flag = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (room[i][j] == 1) {
				visited[i][j] = true;
				q.push(pair<int, int>(i, j));
			}
	count = BFS(q);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (room[i][j] == 0)
				flag = false;
	if (flag) printf("%d\n",count);
	else printf("-1\n");
	return 0;
}