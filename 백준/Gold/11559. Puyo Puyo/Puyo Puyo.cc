#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

char arr[12][6];
bool visited[12][6];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool bfs(int x, int y, char color) {
    vector<pair<int, int>> puyos;
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    puyos.push_back({ x, y });

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && !visited[nx][ny] && arr[nx][ny] == color) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                puyos.push_back({ nx, ny });
            }
        }
    }

    if (puyos.size() >= 4) {
        for (auto& p : puyos) {
            arr[p.first][p.second] = '.';
        }
        return true;
    }
    return false;
}

void apply_gravity() {
    for (int j = 0; j < 6; j++) {
        queue<char> q;
        for (int i = 11; i >= 0; i--) {
            if (arr[i][j] != '.') {
                q.push(arr[i][j]);
            }
        }
        for (int i = 11; i >= 0; i--) {
            if (!q.empty()) {
                arr[i][j] = q.front();
                q.pop();
            }
            else {
                arr[i][j] = '.';
            }
        }
    }
}

int main() {
    FastIO;

    for (int i = 0; i < 12; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 6; j++) {
            arr[i][j] = line[j];
        }
    }

    int res = 0;

    while (true) {
        bool exploded = false;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (arr[i][j] != '.' && !visited[i][j]) {
                    if (bfs(i, j, arr[i][j])) {
                        exploded = true;
                    }
                }
            }
        }

        if (!exploded) break;

        apply_gravity();
        res++;
    }

    cout << res << "\n";

    return 0;
}
