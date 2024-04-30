#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int arr[101][101];
bool visited[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	int cnt = 1;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			
			if (0 < nx && nx <= N && 0 < ny && ny <= M && arr[nx][ny] == 1 && !visited[nx][ny]) {
				cnt++;
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		arr[r][c] = 1;
	}

	int res = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				res = max(res, bfs(i, j));
			}
		}
	}

	cout << res << "\n";
	return 0;
}