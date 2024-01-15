#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int T;
int N, M;
int arr[15][15];
int visited[15][15];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push({ x, y, 0 });
	visited[x][y] = 1;

	while (!q.empty()) {
		int cx, cy, cnt;
		tie(cx, cy, cnt) = q.front();
		q.pop();

		if (arr[cx][cy] == 3) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && arr[nx][ny] != 1) {
				if (visited[nx][ny] == 0) {
					visited[nx][ny] = 1;
					q.push({ nx, ny, cnt + 1 });
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

	cin >> T;
	while (T--) {
		cin >> N >> M;
		memset(visited, 0, sizeof(visited));
		char t;
		int Si, Sj;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> t;
				if (t == 'X') {
					arr[i][j] = 1;
				}
				else if (t == 'O') {
					arr[i][j] = 0;
				}
				else if (t == 'S') {
					arr[i][j] = 2;
					Si = i;
					Sj = j;
				}
				else if (t == 'G') {
					arr[i][j] = 3;
				}
			}
		}
		int res;
		res = bfs(Si, Sj);
		if (res != -1) {
			cout << "Shortest Path: " << res << "\n";
		}
		else cout << "No Exit" << "\n";
	}
	return 0;
}