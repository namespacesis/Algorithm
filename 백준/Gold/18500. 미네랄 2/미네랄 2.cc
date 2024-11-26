#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int R, C;
char arr[100][100];
bool visited[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool bfs(int x, int y) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == R - 1) return false;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

            if (arr[nx][ny] == 'x' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    return true;
}

void move() {
    vector<pair<int, int>> v;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'x' && visited[i][j]) {
                v.push_back({ i, j });
            }
        }
    }

    int cnt = 101;

    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;

        if (y < 0 || y >= C) continue;

        int temp = 0;
        for (int j = x + 1; j < R; j++) {
            if (arr[j][y] == 'x' && !visited[j][y]) break;
            temp++;
        }

        cnt = min(cnt, temp);
    }

    for (int i = 0; i < v.size(); i++) {
        arr[v[i].first][v[i].second] = '.';
    }

    for (int i = 0; i < v.size(); i++) {
        arr[v[i].first + cnt][v[i].second] = 'x';
    }

    return;
}

int main() {
    FastIO;

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    int N;
    cin >> N;

    bool left = true;

    while (N--) {
        int h;
        cin >> h;

        if (left) {
            for (int i = 0; i < C; i++) {
                if (arr[R - h][i] == 'x') {
                    arr[R - h][i] = '.';
                    memset(visited, false, sizeof(visited));
                    for (int j = 0; j < 4; j++) {
                        int nx = R - h + dx[j];
                        int ny = i + dy[j];

                        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

                        if (arr[nx][ny] == 'x' && !visited[nx][ny]) {
                            bool check = bfs(nx, ny);
                            if (check) {
                                move();
                            }
                        }
                    }
                    break;
                }
            }
        }

        else {
            for (int i = C - 1; i >= 0; i--) {
                if (arr[R - h][i] == 'x') {
                    arr[R - h][i] = '.';
                    memset(visited, false, sizeof(visited));
                    for (int j = 0; j < 4; j++) {
                        int nx = R - h + dx[j];
                        int ny = i + dy[j];

                        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

                        if (arr[nx][ny] == 'x' && !visited[nx][ny]) {
                            bool check = bfs(nx, ny);
                            if (check) {
                                move();
                            }
                        }
                    }
                    break;
                }
            }
        }

        left = !left;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}
