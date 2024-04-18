#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int x;
	int y;
};

int N, M;
vector<pair<int, int>> arr[101][101];
bool light_on[101][101];
bool visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
	int chk = 0;
	queue<Node> q;
	q.push({ 1, 1 });
	light_on[1][1] = true;
	visited[1][1] = true;
	chk++;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		for (pair<int, int> next : arr[cur.x][cur.y]) {
			if (!light_on[next.first][next.second]) {
				light_on[next.first][next.second] = true;
				chk++;

				for (int i = 0; i < 4; i++) {
					int nx = next.first + dx[i];
					int ny = next.second + dy[i];

					if (0 < nx && nx <= N && 0 < ny && ny <= N && visited[nx][ny]) {
						q.push({ nx, ny });
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (0 < nx && nx <= N && 0 < ny && ny <= N && !visited[nx][ny]) {
				if (light_on[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	return chk;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		arr[x][y].push_back({ a, b });
	}

	int res = bfs();

	cout << res << "\n";
	return 0;
}