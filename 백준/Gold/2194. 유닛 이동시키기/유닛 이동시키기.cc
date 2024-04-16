#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int x, y, cnt;
};

int N, M;
int A, B;
int K;
int sx, sy, ex, ey;
int arr[501][501];
bool visited[501][501];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool isValid(int x, int y) {
    if (x < 0 || x + A > N || y < 0 || y + B > M) return false;
    for (int i = x; i < x + A; i++) {
        for (int j = y; j < y + B; j++) {
            if (arr[i][j] == -1) return false;
        }
    }
    return true;
}

int bfs(int x, int y) {
    queue<Node> q;
    q.push({ x, y, 0 });
    visited[x][y] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        if (current.x == ex && current.y == ey) {
            return current.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (isValid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny, current.cnt + 1 });
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> A >> B >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        arr[x - 1][y - 1] = -1;
    }

    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    int result = bfs(sx, sy);
    cout << result << "\n";

    return 0;
}
