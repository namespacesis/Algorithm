#include <iostream>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x;
    int y;
};

int N, M;
char arr[300][300];
bool visited[300][300];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int sr, sc;
int er, ec;

bool bfs() {
    queue<Node> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == er && cur.y == ec) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] == '1') {
                arr[nx][ny] = '0';
                visited[nx][ny] = true;
            }
            else {
                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
        }
    }

    return false;
}

int main() {
    FastIO;

    cin >> N >> M;

    cin >> sr >> sc >> er >> ec;
    sr--, sc--, er--, ec--;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int res = 0;

    while (true) {
        memset(visited, false, sizeof(visited));
        res++;
        int ret = bfs();
        if (ret) break;
    }

    cout << res << "\n";

    return 0;
}
