#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int arr[10][9];
int visited[10][9];
int dx1[8] = { -1, 0, 0, 1, 1, 0, 0, -1 };
int dy1[8] = { 0, -1, -1, 0, 0, 1, 1, 0 };
int dx2[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy2[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dx3[8] = { -3, -2, 2, 3, 3, 2, -2, -3 };
int dy3[8] = { -2, -3, -3, -2, 2, 3, 3, 2 };
int R1, C1, R2, C2;

int bfs(int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push({ x, y, 0 });
	visited[x][y] = 1;

	while (!q.empty()) {
		int cx, cy, cnt;
		tie(cx, cy, cnt) = q.front();
		q.pop();

		if (cx == R2 && cy == C2) {
			return cnt;
		}

		for (int i = 0; i < 8; i++) {
			int nx1 = cx + dx1[i];
			int ny1 = cy + dy1[i];
			int nx2 = cx + dx2[i];
			int ny2 = cy + dy2[i];
			int nx3 = cx + dx3[i];
			int ny3 = cy + dy3[i];

			if (nx1 == R2 && ny1 == C2) continue;

			if (nx2 == R2 && ny2 == C2) continue;

			if (0 <= nx3 && nx3 < 10 && 0 <= ny3 && ny3 < 9 && !visited[nx3][ny3]) {
				q.push({ nx3, ny3, cnt + 1 });
				visited[nx3][ny3] = 1;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R1 >> C1;
	cin >> R2 >> C2;

	int res;
	res = bfs(R1, C1);

	cout << res << "\n";
	return 0;
}