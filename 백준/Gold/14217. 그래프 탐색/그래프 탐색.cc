#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
	int x;
	int cnt;
};

int N, M, Q;
int arr[501][501];
int visited[501];

void bfs() {
	queue<Node> q;
	q.push({ 1, 0 });
	visited[1] = 0;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (arr[cur.x][i] && visited[i] == -1) {
				visited[i] = cur.cnt + 1;
				q.push({ i, cur.cnt + 1 });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << visited[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	cin >> Q;

	for (int k = 0; k < Q; k++) {
		int a, i, j;
		cin >> a >> i >> j;

		if (a == 1) {
			arr[i][j] = 1;
			arr[j][i] = 1;
		}
		else if (a == 2) {
			arr[i][j] = 0;
			arr[j][i] = 0;
		}

		memset(visited, -1, sizeof(visited));
		bfs();
	}

	return 0;
}