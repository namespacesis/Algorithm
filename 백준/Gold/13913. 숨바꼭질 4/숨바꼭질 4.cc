#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];
int pointer[100001];

struct Node {
	int x;
	int cnt;
};

void out(int k) {
	if (N != k) {
		out(pointer[k]);
	}
	cout << k << " ";
}

void bfs() {
	queue<Node> q;
	q.push({ N, 0 });

	visited[N] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.x == K) {
			cout << cur.cnt << "\n";
			out(K);
			cout << "\n";
			return;
		}

		if (cur.x + 1 <= 100000 && !visited[cur.x + 1]) {
			visited[cur.x + 1] = true;
			pointer[cur.x + 1] = cur.x;
			q.push({ cur.x + 1, cur.cnt + 1 });
		}

		if (cur.x - 1 >= 0 && !visited[cur.x - 1]) {
			visited[cur.x - 1] = true;
			pointer[cur.x - 1] = cur.x;
			q.push({ cur.x - 1, cur.cnt + 1 });
		}

		if (cur.x * 2 <= 100000 && !visited[cur.x * 2]) {
			visited[cur.x * 2] = true;
			pointer[cur.x * 2] = cur.x;
			q.push({ cur.x * 2, cur.cnt + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	bfs();
	return 0;
}