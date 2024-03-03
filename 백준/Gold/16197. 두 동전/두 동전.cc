#include <iostream>
#include <queue>

using namespace std;

struct Coin {
    int x1;
    int y1;
    int x2;
    int y2;
    int cnt;
};

int N, M;
int r1, c1, r2, c2;
char map[20][20];
bool visited[20][20][20][20];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
    queue<Coin> q;
    q.push({ r1, c1, r2, c2, 0 });

    while (!q.empty()) {
        Coin cur = q.front();
        q.pop();

        if (cur.cnt > 10) return -1;

        int drop = 0;
        if (cur.x1 < 0 || cur.y1 < 0 || cur.x1 >= N || cur.y1 >= M) drop++;
        if (cur.x2 < 0 || cur.y2 < 0 || cur.x2 >= N || cur.y2 >= M) drop++;
        if (drop > 1) continue;
        if (drop == 1) {
            return cur.cnt;
        }

        if (visited[cur.x1][cur.y1][cur.x2][cur.y2]) continue;
        visited[cur.x1][cur.y1][cur.x2][cur.y2] = true;

        for (int i = 0; i < 4; i++) {
            int nx1 = cur.x1 + dx[i];
            int ny1 = cur.y1 + dy[i];
            int nx2 = cur.x2 + dx[i];
            int ny2 = cur.y2 + dy[i];

            if (map[nx1][ny1] == '#') nx1 = cur.x1, ny1 = cur.y1;
            if (map[nx2][ny2] == '#') nx2 = cur.x2, ny2 = cur.y2;
            
            q.push({ nx1, ny1, nx2, ny2, cur.cnt + 1 });
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'o') {
                if (tmp == 0) {
                    r1 = i;
                    c1 = j;
                    tmp++;
                }
                else {
                    r2 = i;
                    c2 = j;
                }
            }
        }
    }

    cout << bfs() << "\n";
    return 0;
}