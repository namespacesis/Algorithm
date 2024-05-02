#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int arr[100][100];
bool visited[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;


	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			
			if (0 <= nx && nx < N && 0 <= ny && ny < M && arr[nx][ny] == 1 && !visited[nx][ny]) {
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
			char t;
			cin >> t;
			if (t == '.') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	int res = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				bfs(i, j);
				res++;
			}
		}
	}

	cout << res << "\n";
	return 0;
}