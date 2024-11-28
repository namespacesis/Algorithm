#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
    int health;
    int distance;
    int guard;
};

int N, H, D;
char arr[500][500];
int visited[500][500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int sc, sr;
int res = 1e9;

void bfs() {
    queue<Node> q;
    q.push({ sc, sr, H, 0, 0 });
    visited[sc][sr] = H;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] == 'E') {
            res = min(res, cur.distance);
            return;
        }

        if (cur.guard >= 0) cur.guard--;
        else cur.health--;

        if (cur.health <= 0) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if (arr[nx][ny] == 'U') {
                if (visited[nx][ny] >= (D + cur.health)) continue;
                visited[nx][ny] = D + cur.health;
                q.push({ nx, ny, cur.health, cur.distance + 1, D });
            }
            else {
                if (visited[nx][ny] >= (cur.guard + cur.health)) continue;
                visited[nx][ny] = cur.guard + cur.health;
                q.push({ nx, ny, cur.health, cur.distance + 1, cur.guard });
            }
        }
    }
    res = -1;
    return;
}

int main() {
    FastIO;

    cin >> N >> H >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                sc = i;
                sr = j;
            }
        }
    }

    bfs();

    cout << res << "\n";

    return 0;
}
