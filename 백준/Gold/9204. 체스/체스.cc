#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

struct Node {
    int x;
    int y;
    int cnt;
    vector<pair<int, int>> path;
};

int T;
bool visited[8][8];
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, -1, -1, 1};

void bfs(int x1, int y1, int x2, int y2) {
    queue<Node> q;
    q.push({x1, x2, 0, {{x1, x2}}});
    visited[x1][x2] = true;

    while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.x == y1 && cur.y == y2) {
			cout << cur.cnt << " ";
			for (auto p : cur.path) {
				cout << (char)(p.first + 'A') << " " << 7 - p.second + 1 << " ";
			}
			cout << endl;
			return;
		}

		for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 8; j++) {
				int nx = cur.x + dx[i] * j;
				int ny = cur.y + dy[i] * j;

				if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) break;
				if (visited[nx][ny]) break;

				visited[nx][ny] = true;

                vector<pair<int, int>> path = cur.path;
				path.push_back({nx, ny});
				q.push({nx, ny, cur.cnt + 1, path});
			}
		}
	}

    cout << "Impossible" << endl;
    return;
}

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        memset(visited, false, sizeof(visited));

        char X1, Y1;
        int X2, Y2;

        cin >> X1 >> X2 >> Y1 >> Y2;

        int x1 = X1 - 'A';
        int y1 = Y1 - 'A';
        int x2 = 7 - X2 + 1;
        int y2 = 7 - Y2 + 1;

        bfs(x1, y1, x2, y2);
    }
}
