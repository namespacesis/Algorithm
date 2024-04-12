#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;
};

int R, C;
char arr[1000][1000];
bool visited[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<Node> fq;

int bfs(int sx, int sy) {
    queue<Node> q;
    q.push({ sx, sy, 0 });
    visited[sx][sy] = true;

    while (!q.empty()) {
        int fireSize = fq.size();
        // 불 확산
        for (int i = 0; i < fireSize; ++i) {
            Node fire = fq.front();
            fq.pop();
            for (int j = 0; j < 4; ++j) {
                int nx = fire.x + dx[j];
                int ny = fire.y + dy[j];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C && arr[nx][ny] == '.') {
                    arr[nx][ny] = 'F';
                    fq.push({ nx, ny, 0 });
                }
            }
        }

        int jSize = q.size();
        // J 이동
        for (int i = 0; i < jSize; ++i) {
            Node cur = q.front();
            q.pop();

            if (cur.x == 0 || cur.x == R - 1 || cur.y == 0 || cur.y == C - 1) {
                return cur.cnt + 1;
            }

            for (int j = 0; j < 4; ++j) {
                int nx = cur.x + dx[j];
                int ny = cur.y + dy[j];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C && arr[nx][ny] == '.' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny, cur.cnt + 1 });
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sx, sy;

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'J') {
                sx = i;
                sy = j;
                arr[i][j] = '.';
            }
            else if (arr[i][j] == 'F') {
                fq.push({ i, j, 0 });
            }
        }
    }

    int result = bfs(sx, sy);

    if (result == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}
