#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M;
int arr[3000][3000];
bool visited[3000][3000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sx, sy;

struct Node {
    int x;
    int y;
    int cnt;
};

int bfs() {
    queue<Node> q;
    q.push({ sx, sy, 0 });
    visited[sx][sy] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] != 1 && arr[nx][ny] != 0) {
                return cur.cnt + 1;
            }

            else if (arr[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({ nx, ny, cur.cnt + 1 });
            }
        }
    }

    return -1;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            arr[i][j] = line[j] - '0';

            if (arr[i][j] == 2) {
                arr[i][j] = 0;
                sx = i, sy = j;
            }
        }
    }

    int res = bfs();

    if (res == -1) {
        cout << "NIE" << "\n";
    }
    else {
        cout << "TAK\n" << res << "\n";
    }

    return 0;
}
