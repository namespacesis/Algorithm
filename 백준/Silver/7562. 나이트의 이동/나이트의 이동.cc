#include <iostream>
#include <queue>
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAXN 300

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;
};

int T, L;
int arr[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int bfs(int cx, int cy, int tx, int ty) {
    queue<Node> q;
    q.push({ cx, cy, 0 });
    visited[cx][cy] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == tx && cur.y == ty) {
            return cur.cnt;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 <= nx && nx < L && 0 <= ny && ny < L && !visited[nx][ny]) {
                q.push({ nx, ny, cur.cnt + 1 });
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    fastIO;

    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        cin >> L;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                visited[i][j] = false;
            }
        }

        int cx, cy, tx, ty;
        cin >> cx >> cy >> tx >> ty;

        int res = bfs(cx, cy, tx, ty);

        cout << res << "\n";
    }

    return 0;
}
