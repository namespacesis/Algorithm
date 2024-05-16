#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;
};

int R, C, N;
int arr[1000][1000];
bool visited[1000][1000];
int dx[10];
int dy[10];

int bfs() {
    queue<Node> q;

    for (int i = 0; i < C; i++) {
        if (arr[0][i] == 1) {
            q.push({ 0, i, 0 });
            visited[0][i] = true;
        }
    }

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == R - 1) {
            return cur.cnt;
        }

        for (int i = 0; i < N; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 <= nx && nx < R && 0 <= ny && ny < C && arr[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny, cur.cnt + 1 });
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dx[i] >> dy[i];
    }

    int res = bfs();

    cout << res << "\n";
    return 0;
}
