#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N, K, R;
int arr[101][101][4];
bool visited[101][101];
vector<pair<int, int>> v;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (visited[nx][ny]) continue;
            if (arr[cx][cy][i]) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int main() {
    FastIO;

    cin >> N >> K >> R;

    for (int i = 0; i < R; i++) {
        int r, c, rr, cc;
        cin >> r >> c >> rr >> cc;
        
        for (int j = 0; j < 4; j++) {
            if (r + dx[j] == rr && c + dy[j] == cc) {
                arr[r][c][j] = 1;
                arr[rr][cc][(j + 2) % 4] = 1;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        v.push_back({ r, c });
    }

    int res = 0;

    for (int i = 0; i < K; i++) {
        memset(visited, false, sizeof(visited));
        bfs(v[i].first, v[i].second);

        for (int j = i + 1; j < K; j++) {
            if (!visited[v[j].first][v[j].second]) res++;
        }
    }

    cout << res << "\n";

    return 0;
}
