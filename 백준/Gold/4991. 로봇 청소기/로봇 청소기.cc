#include <iostream>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x;
    int y;
    int dist;
    int bit;
};

int w, h;
char arr[20][20];
int visited[20][20][1 << 10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sr, sc;
int cnt = 0;
pair<int, int> dust[10];

int bfs() {
    memset(visited, 0x3f, sizeof(visited));
    queue<Node> q;
    q.push({ sr, sc, 0, 0 });
    visited[sr][sc][0] = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.bit == (1 << cnt) - 1) {
            return cur.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            if (arr[nx][ny] != 'x') {
                int next_bit = cur.bit;

                for (int j = 0; j < cnt; j++) {
                    if (nx == dust[j].first && ny == dust[j].second) {
                        if (!(cur.bit & (1 << j))) {
                            next_bit |= (1 << j);
                        }
                        break;
                    }
                }

                if (visited[nx][ny][next_bit] > cur.dist + 1) {
                    visited[nx][ny][next_bit] = cur.dist + 1;
                    q.push({ nx, ny, cur.dist + 1, next_bit });
                }
            }
        }
    }

    return -1;
}

int main() {
    FastIO;

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        cnt = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 'o') {
                    sr = i;
                    sc = j;
                }
                if (arr[i][j] == '*') {
                    dust[cnt] = { i, j };
                    cnt++;
                }
            }
        }

        int res = bfs();

        cout << res << "\n";
    }

    return 0;
}
