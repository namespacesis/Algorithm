#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

struct Node {
	int x;
	int y;
	int cnt;

	bool operator<(const Node& temp) const {
		return cnt > temp.cnt;
	}
};

int N;
int map[50][50];
int visited[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs() {
	priority_queue<Node> pq;
	visited[0][0] = 0;
	pq.push({ 0, 0, 0 });

	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (map[nx][ny] == 1) {
					if (cur.cnt >= visited[nx][ny]) continue;
					visited[nx][ny] = cur.cnt;
					pq.push({ nx, ny, cur.cnt });
				}
				else {
					if (cur.cnt + 1 >= visited[nx][ny]) continue;
					visited[nx][ny] = cur.cnt + 1;
					pq.push({ nx, ny, cur.cnt + 1 });
				}
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
		string line;
		cin >> line;
		for (int j = 0; j < N; j++) {
			map[i][j] = line[j] - '0';
			visited[i][j] = INF;
		}
	}

	bfs();

	int res = visited[N - 1][N - 1];

	cout << res << "\n";
	return 0;
}