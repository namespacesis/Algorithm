#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int R, C;
int arr[1000][1000];
int dx[8] = { 1, -1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    arr[x][y] = 0;
    q.push({ x, y });

    while (!q.empty()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (0 <= nx && nx < R && 0 <= ny && ny < C && arr[nx][ny] != 0) {
                arr[nx][ny] = 0;
                q.push({ nx, ny });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] != 0) {
                res++;
                bfs(i, j);
            }
        }
    }

    cout << res << "\n";
    return 0;
}