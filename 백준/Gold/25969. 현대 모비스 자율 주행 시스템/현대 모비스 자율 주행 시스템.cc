#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y, k, dist, check;
};

int N, M, K;
int arr[200][200];
int visited[200][200][2];
vector<pair<int, int>> pattern;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
    queue<Node> q;
    q.push({ 0, 0, K, 0, 0 });
    visited[0][0][0] = K;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] == 2 && !cur.check) {
            cur.check = 1;
            visited[cur.x][cur.y][1] = cur.k;
        }

        if (cur.x == N - 1 && cur.y == M - 1 && cur.check) {
            return cur.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && arr[nx][ny] != 1 && cur.k > visited[nx][ny][cur.check]) {
                visited[nx][ny][cur.check] = cur.k;
                q.push({ nx, ny, cur.k, cur.dist + 1, cur.check });
            }
        }

        if (cur.k > 0) {
            for (auto& p : pattern) {
                int nx = cur.x + p.first;
                int ny = cur.y + p.second;

                if (0 <= nx && nx < N && 0 <= ny && ny < M && arr[nx][ny] != 1 && cur.k - 1 > visited[nx][ny][cur.check]) {
                    visited[nx][ny][cur.check] = cur.k - 1;
                    q.push({ nx, ny, cur.k - 1, cur.dist + 1, cur.check });
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

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            visited[i][j][0] = -1;
            visited[i][j][1] = -1;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int n;
            cin >> n;
            if (n == 1) pattern.push_back({ i - 2, j - 2 });
        }
    }

    int res = bfs();

    cout << res << "\n";
    return 0;
}
