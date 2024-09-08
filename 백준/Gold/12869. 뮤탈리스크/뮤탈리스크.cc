#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
int arr[3];
bool visited[61][61][61];
int attack[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

struct Node {
	int x;
	int y;
	int z;
	int cnt;
};

int bfs() {
	queue<Node> q;
	q.push({ arr[0], arr[1], arr[2], 0 });
	visited[arr[0]][arr[1]][arr[2]] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.x == 0 && cur.y == 0 && cur.z == 0) {
			return cur.cnt;
		}

		for (int i = 0; i < 6; i++) {
			int nx = cur.x - attack[i][0];
			int ny = cur.y - attack[i][1];
			int nz = cur.z - attack[i][2];

			if (nx < 0) nx = 0;
			if (ny < 0) ny = 0;
			if (nz < 0) nz = 0;

			if (!visited[nx][ny][nz]) {
				visited[nx][ny][nz] = true;
				q.push({ nx, ny, nz, cur.cnt + 1 });
			}
		}
	}
}

int main() {
    FastIO;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int res = bfs();

	cout << res << "\n";

	return 0;
}
