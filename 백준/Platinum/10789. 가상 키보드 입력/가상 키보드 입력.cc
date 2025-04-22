#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

struct Node {
    int x, y;
    int idx;
    int cnt;
};

int R, C;
char arr[50][50];
bool visited[50][50][10002];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int x2x[50][50][4];
int y2y[50][50][4];
string s;
int L;
int res = 1e9;

void bfs() {
    queue<Node> q;
    q.push({ 0, 0, 0, 0 });

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.idx == L) {
            res = min(res, cur.cnt);
            continue;
        }

        if (arr[cur.x][cur.y] == s[cur.idx + 1]) {
            if (visited[cur.x][cur.y][cur.idx + 1]) continue;

            visited[cur.x][cur.y][cur.idx + 1] = true;

            q.push({ cur.x, cur.y, cur.idx + 1, cur.cnt + 1 });
        }

        for (int i = 0; i < 4; i++) {
            int nx = x2x[cur.x][cur.y][i];
            int ny = y2y[cur.x][cur.y][i];

            if (visited[nx][ny][cur.idx]) continue;

            visited[nx][ny][cur.idx] = true;

            q.push({ nx, ny, cur.idx, cur.cnt + 1 });
        }
    }
}

int main() {
    FastIO;

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> s;

    s = '_' + s;

    L = s.length();

    s += '*';

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                while (x >= 0 && x < R && y >= 0 && y < C && arr[x][y] == arr[i][j]) {
                    x += dx[k];
                    y += dy[k];
                }

                if (x < 0 || x >= R || y < 0 || y >= C) {
                    x = i;
                    y = j;
                }

                x2x[i][j][k] = x;
                y2y[i][j][k] = y;
            }
        }
    }

    bfs();

    cout << res << endl;

    return 0;
}
