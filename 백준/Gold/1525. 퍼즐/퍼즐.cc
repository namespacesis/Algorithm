#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

struct Node {
	string order;
	int cnt;
};

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(string state) {
	int res = -1;

	unordered_set<string> visited;
	queue<Node> q;
	
	visited.insert(state);
	q.push({ state, 0 });

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.order == "123456780") {
			if (res == -1 || res > cur.cnt) {
				res = cur.cnt;
			}
		}

		int pos = cur.order.find("0");

		int cx = pos / 3;
		int cy = pos % 3;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				string next = cur.order;

				swap(next[cx * 3 + cy], next[nx * 3 + ny]);

				if (visited.find(next) == visited.end()) {
					visited.insert(next);
					q.push({ next, cur.cnt + 1 });
				}
			}
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string state = "";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char num;
			cin >> num;

			state += num;
		}
	}

	cout << bfs(state) << "\n";
	return 0;
}
