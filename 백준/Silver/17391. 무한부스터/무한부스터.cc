#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M;
int arr[300][300];
int dp[300][300];
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

struct Node {
    int x;
    int y;
    int cnt;
};

int bfs() {
    queue<Node> q;
    q.push({ 0, 0, 0 });
    dp[0][0] = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == N - 1 && cur.y == M - 1) {
            return dp[cur.x][cur.y];
        }

        int cnt = arr[cur.x][cur.y];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= cnt; j++) {
                int nx = cur.x + dx[i] * j;
                int ny = cur.y + dy[i] * j;

                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    if (dp[nx][ny] > cur.cnt + 1) {
                        dp[nx][ny] = cur.cnt + 1;
                        q.push({ nx, ny, cur.cnt + 1 });
                    }
                }
            }
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            dp[i][j] = 301;
        }
    }

    int res = bfs();

    cout << res << "\n";
    
    return 0;
}
