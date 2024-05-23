#include <iostream>
#include <queue>

using namespace std;

struct Chess {
	int x;
	int y;
	int cnt;
};

int N;
int r1, c1, r2, c2;
int arr[200][200];
bool visited[200][200];
int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };

int bfs() {
	queue<Chess> q;
	q.push({ r1, c1 });
	visited[r1][c1] = true;
	
	while(!q.empty()) {
		Chess cur = q.front();
		q.pop();

		if (cur.x == r2 && cur.y == c2) {
			return cur.cnt;
		}

		for (int i = 0; i < 6; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny, cur.cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	cin >> r1 >> c1 >> r2 >> c2;

	cout << bfs() << "\n";
	return 0;
}