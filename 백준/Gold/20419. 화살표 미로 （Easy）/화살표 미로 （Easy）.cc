#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int x;
	int y;
	int kL;
	int kR;
};

int R, C, K;
int arr[50][50];
bool visited[50][50][2][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

string bfs() {
	queue<Node> q;
	q.push({ 0, 0, K, K });
	visited[0][0][0][0] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.x == R - 1 && cur.y == C - 1) {
			return "Yes";
		}

		int nx = cur.x + dx[arr[cur.x][cur.y]];
		int ny = cur.y + dy[arr[cur.x][cur.y]];

		if (0 <= nx && nx < R && 0 <= ny && ny < C) {
			if (!visited[nx][ny][cur.kL][cur.kR]) {
				visited[nx][ny][cur.kL][cur.kR] = true;
				q.push({ nx, ny, cur.kL, cur.kR });
			}
		}

		if (cur.kL > 0) {
			int nx = cur.x + dx[(arr[cur.x][cur.y] + 3) % 4];
			int ny = cur.y + dy[(arr[cur.x][cur.y] + 3) % 4];

			if (0 <= nx && nx < R && 0 <= ny && ny < C) {
				if (cur.kL > 0 && !visited[nx][ny][cur.kL - 1][cur.kR]) {
					visited[nx][ny][cur.kL - 1][cur.kR] = true;
					q.push({ nx, ny, cur.kL - 1, cur.kR });
				}
			}
		}
		
		if (cur.kR > 0) {
			int nx = cur.x + dx[(arr[cur.x][cur.y] + 1) % 4];
			int ny = cur.y + dy[(arr[cur.x][cur.y] + 1) % 4];

			if (0 <= nx && nx < R && 0 <= ny && ny < C) {
				if (cur.kR > 0 && !visited[nx][ny][cur.kL][cur.kR - 1]) {
					visited[nx][ny][cur.kL][cur.kR - 1] = true;
					q.push({ nx, ny, cur.kL, cur.kR - 1 });
				}
			}
		}
	}

	return "No";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char arrow;
			cin >> arrow;
			if (arrow == 'D') arr[i][j] = 0;
			else if (arrow == 'R') arr[i][j] = 1;
			else if (arrow == 'U') arr[i][j] = 2;
			else if (arrow == 'L') arr[i][j] = 3;
		}
	}

	cout << bfs() << "\n";
	return 0;
}