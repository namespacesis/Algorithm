#include <iostream>
#include <queue>

using namespace std;

int N, M;
int max_h;
int res;
int map[52][52];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int h) {
	map[0][0] = h;

	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1) continue;

			if (map[nx][ny] < h) {
				map[nx][ny] = h;
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

	for (int i = 1; i <= N; i++) {
		string line;
		cin >> line;
		for (int j = 1; j <= M; j++) {
			map[i][j] = line[j - 1] - '0';
			if (max_h < map[i][j]) max_h = map[i][j];
		}
	}

	for (int h = 1; h <= max_h; h++) {
		bfs(h);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] < h) {
					res++;
					map[i][j] = h;
				}
			}
		}
	}

	cout << res << "\n";
	return 0;
}