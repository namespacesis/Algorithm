#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int L, R, C;
int Sf, Sx, Sy;
char arr[30][30][30];
int visited[30][30][30];
int df[2] = { 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
	queue<tuple<int, int, int, int>> q;
	q.push({ Sf, Sx, Sy, 0 });
	visited[Sf][Sx][Sy] = 1;

	while (!q.empty()) {
		int cf, cx, cy, cnt;
		tie(cf, cx, cy, cnt) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 <= nx && nx < R && 0 <= ny && ny < C && !visited[cf][nx][ny]) {
				if (arr[cf][nx][ny] == '.') {
					q.push({ cf, nx, ny, cnt + 1 });
					visited[cf][nx][ny] = 1;
				}
				if (arr[cf][nx][ny] == 'E') return cnt + 1;
			}
		}

		for (int i = 0; i < 2; i++) {
			int nf = cf + df[i];

			if (0 <= nf && nf < L && !visited[nf][cx][cy]) {
				if (arr[nf][cx][cy] == '.') {
					q.push({ nf, cx, cy, cnt + 1 });
					visited[nf][cx][cy] = 1;
				}
				if (arr[nf][cx][cy] == 'E') return cnt + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) break;

		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> arr[i][j][k];
					
					if (arr[i][j][k] == 'S') {
						Sf = i, Sx = j, Sy = k;
					}
				}
			}
		}

		int res;
		res = bfs();

		if (res == -1) {
			cout << "Trapped!" << "\n";
		}
		else {
			cout << "Escaped in " << res << " minute(s)." << "\n";

		}
	}

	return 0;
}