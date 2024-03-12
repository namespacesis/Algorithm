#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[50][50];
bool visited[50][50][4][2][2]; // x, y, dir, C, D
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct State {
	int x;
	int y;
	int prev;
	int cnt;
	bool C;
	bool D;
};

int bfs(int x, int y) {
	queue<State> q;
	q.push({ x, y, -1, 0, false, false });

	while (!q.empty()) {
		State cur = q.front();
		int cx = cur.x;
		int cy = cur.y;
		int prev = cur.prev;
		int cnt = cur.cnt;
		bool C = cur.C;
		bool D = cur.D;
		q.pop();

		if (C && D) return cnt;

		for (int i = 0; i < 4; i++) {
			if (i == prev) continue;

			int nx = cx + dx[i];
			int ny = cy + dy[i];
			bool nC = C;
			bool nD = D;

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (!visited[nx][ny][i][C][D] && map[nx][ny] != '#') {
					if (map[nx][ny] == 'C') nC = true;
					else if (map[nx][ny] == 'D') nD = true;

					visited[nx][ny][i][nC][nD] = true;
					q.push({ nx, ny, i, cnt + 1, nC, nD });
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

	int sx, sy;
	bool flag = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (map[i][j] == 'C') {
				if (!flag) flag = true;
				else if (flag) map[i][j] = 'D';
			}
		}
	}

	cout << bfs(sx, sy) << "\n";
	return 0;
}