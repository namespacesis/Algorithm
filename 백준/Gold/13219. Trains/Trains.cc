#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int Ax, Ay, Bx, By;
int arr[401][401];
int visited[401][401];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct train {
	int cx;
	int cy;
	long long cnt;

	bool operator<(const train &temp) const {
		return cnt > temp.cnt;
	}
};

long long bfs(int x, int y) {
	priority_queue<train> q;
	q.push({ x, y, arr[x][y]});
	visited[x][y] = 1;

	long long total = -1;

	while (!q.empty()) {
		train t = q.top();
		q.pop();

		if (t.cx == Bx && t.cy == By) {
			return t.cnt;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = t.cx + dx[i];
			int ny = t.cy + dy[i];

			if (0 < nx && nx <= N && 0 < ny && ny <= N && !visited[nx][ny] && arr[nx][ny] != -1) {
				visited[nx][ny] = 1;
				q.push({ nx, ny, t.cnt + arr[nx][ny]});
			}
		}
	}
	return total;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> Ay >> Ax >> By >> Bx;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	long long res = bfs(Ax, Ay);

	if (arr[Ax][Ay] == -1) res = -1;

	cout << res << "\n";

	return 0;
}