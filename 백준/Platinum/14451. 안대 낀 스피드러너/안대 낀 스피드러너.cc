#include <iostream>
#include <queue>
#define MAX_N 20

using namespace std;

int N;
char arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N][MAX_N][4][4];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dir[3] = { -1, 0, 1 };

struct Node {
	int x1, y1;
	int x2, y2;
	int dir1;
	int dir2;
	int cnt;
};

int bfs() {
	queue<Node> q;
	q.push({ N - 1, 0, N - 1, 0, 3, 0, 0 });
	visited[N - 1][0][N - 1][0][3][0] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.x1 == 0 && cur.x2 == 0 && cur.y1 == N - 1 && cur.y2 == N - 1) {
			return cur.cnt;
		}

		for (int i = 0; i < 3; i++) {
			int ndir1 = cur.dir1;
			int ndir2 = cur.dir2;
			int nx1 = cur.x1;
			int nx2 = cur.x2;
			int ny1 = cur.y1;
			int ny2 = cur.y2;

			if (nx1 != 0 || ny1 != N - 1) {
				ndir1 = (ndir1 + dir[i] + 4) % 4;

				if (ndir1 == cur.dir1) {
					nx1 += dx[ndir1];
					ny1 += dy[ndir1];

					if (0 > nx1 || nx1 >= N || 0 > ny1 || ny1 >= N || arr[nx1][ny1] == 'H') {
						nx1 -= dx[ndir1];
						ny1 -= dy[ndir1];
					}
				}
			}

			if (nx2 != 0 || ny2 != N - 1) {
				ndir2 = (ndir2 + dir[i] + 4) % 4;

				if (ndir2 == cur.dir2) {
					nx2 += dx[ndir2];
					ny2 += dy[ndir2];

					if (0 > nx2 || nx2 >= N || 0 > ny2 || ny2 >= N || arr[nx2][ny2] == 'H') {
						nx2 -= dx[ndir2];
						ny2 -= dy[ndir2];
					}
				}
			}

			if (!visited[nx1][ny1][nx2][ny2][ndir1][ndir2]) {
				visited[nx1][ny1][nx2][ny2][ndir1][ndir2] = true;
				q.push({ nx1, ny1, nx2, ny2, ndir1, ndir2, cur.cnt + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int res = bfs();

	cout << res << "\n";
	return 0;
}