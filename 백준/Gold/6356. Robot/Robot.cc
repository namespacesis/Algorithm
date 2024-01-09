#include <iostream>
#include <queue>;

using namespace std;

int M, N;
int Si, Sj;
string Sr;
int Ei, Ej;
int arr[51][51];
int visited[51][51][5];
int dcx[3] = { 0, 1, 1 };
int dcy[3] = { 1, 1, 0 };
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

bool cir(int x, int y) {
	for (int i = 0; i < 3; i++) {
		int nx = x + dcx[i];
		int ny = y + dcy[i];

		if (arr[nx][ny] != 0) {
			return false;
		}
	}
	return true;
}

void bfs(int x, int y, int d) {
	queue<Robot> q;
	q.push({ x, y, d, 0 });
	visited[x][y][d] = 0;

	while (!q.empty()) {
		Robot R = q.front();
		q.pop();

		if (R.cx == Ei && R.cy == Ej) {
			continue;
		}

		int flag = 0;

		for (int i = 1; i <= 3; i++) {
			int nx = R.cx + (dx[R.dir] * i);
			int ny = R.cy + (dy[R.dir] * i);

			if (flag + 1 < i) {
				break;
			}

			if (0 <= nx && nx < M - 1 && 0 <= ny && ny < N - 1 && arr[nx][ny] == 0 && cir(nx, ny)) {
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

	while (true) {
		cin >> M >> N;
		if (M == 0 && N == 0) break;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 1; k <= 4; k++) {
					visited[i][j][k] = 999999;
				}
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
	
		cin >> Si >> Sj;
		
		Si -= 1;
		Sj -= 1;
		cin >> Ei >> Ej >> Sr;
		Ei -= 1;
		Ej -= 1;
		int rr;
		if (Sr == "east") rr = 1;
		else if (Sr == "west") rr = 2;
		else if (Sr == "south") rr = 3;
		else if (Sr == "north") rr = 4;
		bfs(Si, Sj, rr);
		int res = 999999;
		for (int i = 1; i <= 4; i++) {
			res = min(res, visited[Ei][Ej][i]);
		}
		if (res == 999999) {
			res = -1;
		}
		cout << res << "\n";
	}
	return 0;
}