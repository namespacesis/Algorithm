#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

struct Node {
    int x;
    int y;
    int cost;

    bool operator < (const Node& n) const {
        return cost > n.cost;
    }
};

int N;
int arr[125][125];
int visited[125][125];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
    priority_queue<Node> pq;
    pq.push({ 0, 0, arr[0][0] });
    visited[0][0] = arr[0][0];

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.x == N - 1 && cur.y == N - 1) {
            return cur.cost;
        }

        for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (visited[nx][ny] > cur.cost + arr[nx][ny]) {
				visited[nx][ny] = cur.cost + arr[nx][ny];
				pq.push({ nx, ny, visited[nx][ny] });
			}
		}
    }
}

int main() {
    FastIO;

    int tc = 0;

    while (true) {
        cin >> N;

        if (N == 0) break;

        tc++;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                visited[i][j] = 1e9;
            }
        }

        int res = bfs();

        cout << "Problem " << tc << ": " << res << "\n";
    }

    return 0;
}
