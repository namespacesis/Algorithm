#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1000][1000];
bool visited[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

pair<int, int> change(int x, int y) {
	if (x == N) x = 0;
	else if (x == -1) x = N - 1;
	if (y == M) y = 0;
	else if (y == -1) y = M - 1;

	return { x, y };
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			pair<int, int> c = change(nx, ny);
			nx = c.first;
			ny = c.second;

			if (!visited[nx][ny] && arr[nx][ny] == 0) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int res = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				bfs(i, j);
				res++;
			}
		}
	}

	cout << res << "\n";
	return 0;
}