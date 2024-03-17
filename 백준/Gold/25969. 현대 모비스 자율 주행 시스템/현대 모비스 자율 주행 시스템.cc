#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int x, y, k, dist;
	bool check;
};

int N, M, K;
int arr[200][200];
bool visited[200][200][31][2];
vector<pair<int, int>> pattern;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
	queue<Node> q;
	visited[0][0][K][0] = true;
	q.push({ 0, 0, K, false, 0 });

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.check && cur.x == N - 1 && cur.y == M - 1) {
			return cur.dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && arr[nx][ny] != 1) {
				if (cur.check && !visited[nx][ny][cur.k][1]) {
					visited[nx][ny][cur.k][1] = true;
					q.push({ nx, ny, cur.k, cur.dist + 1, cur.check });
				}
				else if (!cur.check && !visited[nx][ny][cur.k][0]) {
					if (arr[nx][ny] == 2) {
						visited[nx][ny][cur.k][1] = true;
						q.push({ nx, ny, cur.k, cur.dist + 1, true });
					}
					else {
						visited[nx][ny][cur.k][0] = true;
						q.push({ nx, ny, cur.k, cur.dist + 1, cur.check });
					}
				}
			}

			if (cur.k > 0) {
				for (pair<int, int> p : pattern) {
					int nx = cur.x + p.first;
					int ny = cur.y + p.second;

					if (0 <= nx && nx < N && 0 <= ny && ny < M && arr[nx][ny] != 1) {
						if (cur.check && !visited[nx][ny][cur.k - 1][1]) {
							visited[nx][ny][cur.k - 1][1] = true;
							q.push({ nx, ny, cur.k - 1, cur.dist + 1, cur.check });
						}
						else if (!cur.check && !visited[nx][ny][cur.k - 1][0]) {
							if (arr[nx][ny] == 2) {
								visited[nx][ny][cur.k - 1][1] = true;
								q.push({ nx, ny, cur.k - 1, cur.dist + 1, true });
							}
							else {
								visited[nx][ny][cur.k - 1][0] = true;
								q.push({ nx, ny, cur.k - 1, cur.dist + 1, cur.check });
							}
						}
					}
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
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int n;
			cin >> n;
			if (n == 1) pattern.push_back({ i - 2, j - 2 });
		}
	}

	int res = bfs();

	cout << res << "\n";
	return 0;
}