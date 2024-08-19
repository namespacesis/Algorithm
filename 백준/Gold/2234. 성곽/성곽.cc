#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M;
int arr[50][50];
bool visited[50][50];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    int cnt = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int check = arr[cx][cy] & (1 << i);

            if (!check) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({ nx, ny });
                    }
                }
            }
        }
    }

    return cnt;
}

int main() {
    FastIO;

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int res1 = 0, res2 = 0, res3 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                res1++;
                res2 = max(res2, bfs(i, j));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int check = arr[i][j] & (1 << k);

                if (check) {
                    arr[i][j] -= (1 << k);
                    memset(visited, false, sizeof(visited));
                    res3 = max(res3, bfs(i, j));
                    arr[i][j] += (1 << k);
                }
            }
        }
    }

    cout << res1 << "\n" << res2 << "\n" << res3 << "\n";

    return 0;
}
