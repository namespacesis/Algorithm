#include <iostream>
#include <queue>

using namespace std;

struct State {
	int x, y;
	int cnt, dist; // 벽 부순 횟수, 이동 거리
	int type; // 낮: 1, 밤: -1
};

int N, M, K;
int map[1000][1000];
bool visited[1000][1000][11];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
	queue<State> q;
	q.push({ 0, 0, 0, 1, 1 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cnt = q.front().cnt;
		int dist = q.front().dist;
		int day = q.front().type;
		q.pop();

		if (cx == N - 1 && cy == M - 1) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (map[nx][ny] == 0 && !visited[nx][ny][cnt]) {
				visited[nx][ny][cnt] = true;
				q.push({ nx, ny, cnt, dist + 1, -day });
			}

			if (map[nx][ny] == 1 && cnt < K && !visited[nx][ny][cnt + 1]) {
				if (day == 1) {
					visited[nx][ny][cnt + 1] = true;
					q.push({ nx, ny, cnt + 1, dist + 1, -day });
				}
				else {
					q.push({ cx, cy, cnt, dist + 1, -day });
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

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			map[i][j] = line[j] - '0';
		}
	}

	cout << bfs() << "\n";
	return 0;
}