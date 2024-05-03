#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[40][40];
bool visited[40][40];
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[nx][ny] || arr[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;

	while (cin >> N) {
		tc++;

		for (int i = 0; i < N; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < N; j++) {
				arr[i][j] = line[j] - '0';
				visited[i][j] = false;
			}
		}

		int res = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && arr[i][j] == 1) {
					bfs(i, j);
					res++;
				}
			}
		}

		cout << "Case #" << tc << ": " << res << "\n";
	}

	return 0;
}