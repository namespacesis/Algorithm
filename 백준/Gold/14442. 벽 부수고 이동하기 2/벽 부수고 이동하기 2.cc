#include <iostream>
#include <queue>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

struct Node {
	int x;
	int y;
	int cnt;
	int dist;
};

int N, M, K;
int arr[1001][1001];
bool visited[1001][1001][11];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
	queue<Node> q;
	q.push({ 0, 0, 0, 1 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.x == N - 1 && cur.y == M - 1) {
			return cur.dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (arr[nx][ny] == 0 && !visited[nx][ny][cur.cnt]) {
				visited[nx][ny][cur.cnt] = true;
				q.push({ nx, ny, cur.cnt, cur.dist + 1 });
			}
			else if (arr[nx][ny] == 1 && cur.cnt < K && !visited[nx][ny][cur.cnt + 1]) {
				visited[nx][ny][cur.cnt + 1] = true;
				q.push({ nx, ny, cur.cnt + 1, cur.dist + 1 });
			}
		}
	}
	return -1;
}

int main() {
    FastIO;

    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        string line;
		cin >> line;
        for (int j = 0; j < M; j++) {
			arr[i][j] = line[j] - '0';
        }
    }

	cout << bfs() << "\n";
	return 0;
}