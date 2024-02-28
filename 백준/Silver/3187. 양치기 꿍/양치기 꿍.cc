#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int R, C;
char map[250][250];
bool visited[250][250];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int res1, res2;

void bfs(int x, int y) {
	int tmp1 = 0;
	int tmp2 = 0;

	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int cx, cy;
		tie(cx, cy) = q.front();
		q.pop();

		if (map[cx][cy] == 'k') tmp1++;
		else if (map[cx][cy] == 'v') tmp2++;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (map[nx][ny] != '#' && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	if (tmp1 > tmp2) res1 += tmp1;
	else res2 += tmp2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	res1 = 0;
	res2 = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if ((map[i][j] == 'v' || map[i][j] == 'k') && !visited[i][j]) {
				visited[i][j] = true;
				bfs(i, j);
			}
		}
	}

	cout << res1 << " " << res2 << "\n";
	return 0;
}