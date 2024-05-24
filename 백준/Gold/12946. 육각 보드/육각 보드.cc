#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[50][50];
int res = 0;
int dx[6] = { 0, 0, -1, -1, 1, 1 };
int dy[6] = { -1, 1, 0, 1, -1, 0 };

bool isValid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

void dfs(int x, int y, int cnt) {
    arr[x][y] = cnt;
    res = max(res, 1);

    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny)) {
            if (arr[nx][ny] == -2) {
                dfs(nx, ny, 1 - cnt);
                res = max(res, 2);
            }
            else if (arr[nx][ny] == cnt) {
                res = max(res, 3);
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char t;
            cin >> t;

            if (t == '-') arr[i][j] = -1;
            else arr[i][j] = -2;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == -2) {
                dfs(i, j, 0);
                if (res == 3) {
                    cout << res << "\n";
                    return 0;
                }
            }
        }
    }

    cout << res << "\n";
    return 0;
}
