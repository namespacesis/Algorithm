#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[300][300];
bool visited[300][300];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

bool bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == M - 1 && y == N - 1) {
			return true;
		}

		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (!visited[nx][ny] && arr[nx][ny] == 1) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	bool res = bfs();

	if (res) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

	return 0;
}