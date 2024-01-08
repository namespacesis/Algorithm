#include <iostream>
#include <queue>;

using namespace std;

int M, N;
int Si, Sj, Sr;
int Ei, Ej, Er;
int arr[101][101];
int visited[101][101][5];
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int dcl[5] = { 0, 4, 3, 1, 2 };
int dcr[5] = { 0, 3, 4, 2, 1 };

struct Robot {
	int cx;
	int cy;
	int dir;
	int cnt;
};

void bfs(int x, int y, int d) {
	queue<Robot> q;
	q.push({ x, y, d, 0 });
	visited[x][y][d] = 0;

	while (!q.empty()) {
		Robot R = q.front();
		q.pop();

		if (R.cx == Ei && R.cy == Ej && R.dir == Er) {
			continue;
		}
		
		int flag = 0;
		
		for (int i = 1; i <= 3; i++) {
			int nx = R.cx + (dx[R.dir] * i);
			int ny = R.cy + (dy[R.dir] * i);

			if (flag + 1 < i) {
				break;
			}

			if (1 <= nx && nx <= M && 1 <= ny && ny <= N && arr[nx][ny] == 0) {
				flag = i;
				if (R.cnt + 1 < visited[nx][ny][R.dir]) {
					visited[nx][ny][R.dir] = R.cnt + 1;
					q.push({ nx, ny, R.dir, R.cnt + 1 });
				}
			}
		}

		for (int j = 0; j <= 1; j++) {
			if (j == 0) {
				int ndir = dcl[R.dir];
				if (R.cnt + 1 < visited[R.cx][R.cy][ndir]) {
					visited[R.cx][R.cy][ndir] = R.cnt + 1;
					q.push({ R.cx, R.cy, ndir, R.cnt + 1 });
				}
			}
			else {
				int ndir = dcr[R.dir];
				if (R.cnt + 1 < visited[R.cx][R.cy][ndir]) {
					visited[R.cx][R.cy][ndir] = R.cnt + 1;
					q.push({ R.cx, R.cy, ndir, R.cnt + 1 });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= 4; k++) {
				visited[i][j][k] = 999999;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> Si >> Sj >> Sr;
	cin >> Ei >> Ej >> Er;
	bfs(Si, Sj, Sr);
	cout << visited[Ei][Ej][Er] << "\n";
	return 0;
}