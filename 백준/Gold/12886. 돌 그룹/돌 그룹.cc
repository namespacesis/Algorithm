#include <iostream>
#include <queue>

using namespace std;

struct Stone {
	int a;
	int b;
	int c;
};

int A, B, C;
bool visited[1501][1501];

bool bfs() {
	queue<Stone> q;
	q.push({ A, B, C });
	visited[A][B] = true;

	while (!q.empty()) {
		Stone cur = q.front();
		q.pop();

		if (cur.a == cur.b && cur.b == cur.c) {
			return true;
		}

		if (cur.a != cur.b) {
			int na = cur.a > cur.b ? cur.a - cur.b : cur.a + cur.a;
			int nb = cur.a > cur.b ? cur.b + cur.b : cur.b - cur.a;

			if (!visited[na][nb]) {
				visited[na][nb] = true;
				q.push({ na, nb, cur.c });
			}
		}

		if (cur.b != cur.c) {
			int nb = cur.b > cur.c ? cur.b - cur.c : cur.b + cur.b;
			int nc = cur.b > cur.c ? cur.c + cur.c : cur.c - cur.b;

			if (!visited[nb][nc]) {
				visited[nb][nc] = true;
				q.push({ cur.a, nb, nc });
			}
		}

		if (cur.a != cur.c) {
			int na = cur.a > cur.c ? cur.a - cur.c : cur.a + cur.a;
			int nc = cur.a > cur.c ? cur.c + cur.c : cur.c - cur.a;

			if (!visited[na][nc]) {
				visited[na][nc] = true;
				q.push({ na, cur.b, nc });
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> B >> C;

	int res = bfs() ? 1 : 0;
	
	cout << res << "\n";
	return 0;
}