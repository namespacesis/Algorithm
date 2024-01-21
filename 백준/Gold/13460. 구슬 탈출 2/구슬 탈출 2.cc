#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
char arr[10][10];
int visited[10][10][10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int rx, ry, bx, by;

void move(int& x, int& y, int& dis, int i) {
	while (arr[x + dx[i]][y + dy[i]] != '#' && arr[x][y] != 'O') {
		x += dx[i];
		y += dy[i];
		dis += 1;
	}
}

int bfs() {
	queue<tuple<int, int, int, int, int>> q;
	q.push({ rx, ry, bx, by, 0 });
	visited[rx][ry][bx][by] = 1;

	while (!q.empty()) {
		int crx, cry, cbx, cby, cnt;
		tie(crx, cry, cbx, cby, cnt) = q.front();
		q.pop();

		if (cnt >= 10) return -1;

		for (int i = 0; i < 4; i++) {
			int nrx = crx, nry = cry, nbx = cbx, nby = cby;
			int rdis = 0, bdis = 0;

			move(nrx, nry, rdis, i);
			move(nbx, nby, bdis, i);

			if (arr[nbx][nby] == 'O') continue;
			if (arr[nrx][nry] == 'O') {
				return cnt + 1;
			}

			if (nrx == nbx && nry == nby) {
				if (rdis > bdis) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (!visited[nrx][nry][nbx][nby]) {
				visited[nrx][nry][nbx][nby] = 1;
				q.push({ nrx, nry, nbx, nby, cnt + 1 });
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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (arr[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}

	int res;
	res = bfs();

	cout << res << "\n";
	return 0;
}