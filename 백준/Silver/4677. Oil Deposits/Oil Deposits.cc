#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
char arr[100][100];
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    arr[x][y] = '*';

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (arr[nx][ny] == '@') {
                arr[nx][ny] = '*';
                q.push({ nx, ny });
            }
        }
    }
}

int main() {
    FastIO;

    int res;

    while (true) {
        cin >> N >> M;

        if (N == 0 && M == 0) break;

        res = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == '@') {
                    bfs(i, j);
                    res++;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}