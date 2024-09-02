#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define INT_MAX 1e9

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;

    bool operator<(const Node& n) const {
        return cnt > n.cnt;
    }
};

int H, W;
int sx, sy;
char arr[500][500];
int visited[500][500];
int dx[8] = { 0, 1, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 1, 1, 1, -1, 0, 0, -1, -1 };

int bfs() {
    priority_queue<Node> pq;
    pq.push({ sx, sy, 0 });
    visited[sx][sy] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (arr[cur.x][cur.y] == '*') {
            return cur.cnt;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 <= nx && nx < H && 0 <= ny && ny < W) {
                if (arr[nx][ny] != '#') {
                    int ncnt = cur.cnt + (i < 3 ? 0 : 1);
                    if (ncnt < visited[nx][ny]) {
                        visited[nx][ny] = ncnt;
                        pq.push({ nx, ny, ncnt });
                    }
                }
            }
        }
    }
    
    return -1;
}

int main() {
    FastIO;

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
            visited[i][j] = INT_MAX;
            
            if (arr[i][j] == 'K') {
                sx = i;
                sy = j;
            }
        }
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}
