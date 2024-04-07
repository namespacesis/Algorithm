#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int x;
	int y;
	int bits;
	int time;
};

int N, M;
char arr[50][50];
bool visited[50][50][1 << 5];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int startX, startY;
int totalBits;

int bfs() {
	queue<Node> q;
	q.push({ startX, startY, 0, 0 });
	visited[startX][startY][0] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (arr[cur.x][cur.y] == 'E' && cur.bits == totalBits) {
			return cur.time;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if ('0' <= arr[nx][ny] && arr[nx][ny] < '5') {
					int nbits = cur.bits | (1 << arr[nx][ny] - '0');

					if (!visited[nx][ny][nbits]) {
						visited[nx][ny][nbits] = true;
						q.push({ nx, ny, nbits, cur.time + 1 });
					}
				}
				else if (arr[nx][ny] != '#') {
					if (!visited[nx][ny][cur.bits]) {
						visited[nx][ny][cur.bits] = true;
						q.push({ nx, ny, cur.bits, cur.time + 1 });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	char cnt = '0';

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'S') {
				startX = i;
				startY = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'X') {
				arr[i][j] = cnt++;
			}
		}
	}

	totalBits = (1 << cnt - '0') - 1;

	int res = bfs();

	cout << res << "\n";
	return 0;
}