#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int arr[100][100];
int visited[100][100];
int dx[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dy[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
queue<tuple<int, int, int>> q;

int bfs() {
	while (!q.empty()) {
		int cx, cy, cnt;
		tie(cx, cy, cnt) = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny]) {
				if (arr[nx][ny] == 0) {
					q.push({ nx, ny, cnt + 1 });
					visited[nx][ny] = 1;
				}
				else if (arr[nx][ny] == 3) {
					return cnt + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	char t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> t;
			if (t == '.') arr[i][j] = 0;
			else if (t == '#') arr[i][j] = 1;
			else if (t == 'K') {
				arr[i][j] = 2;
				q.push({ i, j, 0 });
				visited[i][j] = 1;
			}
			else if (t == 'X') arr[i][j] = 3;
		}
	}
	int res;
	res = bfs();

	cout << res << "\n";
	return 0;
}