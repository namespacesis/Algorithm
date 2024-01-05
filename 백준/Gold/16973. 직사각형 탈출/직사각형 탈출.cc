#include <iostream>
#include <queue>

using namespace std;

int N, M, H, W, Sr, Sc, Fr, Fc;
int arr[1001][1001];
int sum[1001][1001];
int visited[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct square {
    int x, y, cnt;
};

bool check(int x, int y) {
    int total = sum[x + H - 1][y + W - 1] - sum[x + H - 1][y - 1] - sum[x - 1][y + W - 1] + sum[x - 1][y - 1];
    return total == 0;
}

int bfs() {
    queue<square> q;
    q.push({ Sr, Sc, 0 });
    visited[Sr][Sc] = 1;

    while (!q.empty()) {
        square sq = q.front();
        q.pop();
        int cx = sq.x;
        int cy = sq.y;
        int cnt = sq.cnt;

        if (cx == Fr && cy == Fc) return cnt;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx > 0 && ny > 0 && nx + H - 1 <= N && ny + W - 1 <= M && !visited[nx][ny] && check(nx, ny)) {
                q.push({ nx, ny, cnt + 1 });
                visited[nx][ny] = 1;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

    cout << bfs() << "\n";
    return 0;
}
