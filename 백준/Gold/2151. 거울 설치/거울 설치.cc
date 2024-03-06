#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;

int N;
char map[50][50];
int visited[50][50][4];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

struct Node {
	int x, y, dir, cost;
	bool operator<(const Node& other) const {
		return cost > other.cost;
	}
};

struct Dir {
	int dir1;
	int dir2;
};

Dir changeDir(int dir) {
	if (dir <= 1) return { 2, 3 };
	return { 0, 1 };
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	Node s;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				s.x = i, s.y = j;
			}

			for (int k = 0; k < 4; k++) {
				visited[i][j][k] = INF;
			}
		}
	}
	map[s.x][s.y] = '*';

	priority_queue<Node> pq;
	s.cost = 0;
	for (int i = 0; i < 4; i++) {
		s.dir = i;
		pq.push(s);
	}

	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();

		if (visited[cur.x][cur.y][cur.dir] <= cur.cost) continue;
		visited[cur.x][cur.y][cur.dir] = cur.cost;

		Node next;
		next.x = cur.x + dx[cur.dir];
		next.y = cur.y + dy[cur.dir];
		next.cost = cur.cost;

		if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N || map[next.x][next.y] == '*') continue;

		if (map[next.x][next.y] == '!') {
			next.dir = cur.dir;
			pq.push(next);

			next.cost++;
			Dir ndir = changeDir(cur.dir);

			next.dir = ndir.dir1;
			pq.push(next);
			next.dir = ndir.dir2;
			pq.push(next);
		}
		else if (map[next.x][next.y] == '.') {
			next.dir = cur.dir;
			pq.push(next);
		}
		else if (map[next.x][next.y] == '#') {
			cout << next.cost << "\n";
			break;
		}
	}
	
	return 0;
}