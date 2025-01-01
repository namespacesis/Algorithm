#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
char arr[100][100];
bool visited[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny] || arr[nx][ny] == '#') continue;

            if (arr[nx][ny] == '+') {
                while (arr[nx][ny] == '+') {
                    nx += dx[i];
                    ny += dy[i];
                }
                
                if (arr[nx][ny] == '#') {
                    nx -= dx[i];
                    ny -= dy[i];
                }

                if (visited[nx][ny]) continue;
            }

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'W') {
                q.push({ i, j });
                visited[i][j] = true;
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '.' && !visited[i][j]) {
                arr[i][j] = 'P';
            }
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}
