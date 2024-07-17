#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int H, W;
int arr[1000][1000];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
    FastIO;

    cin >> H >> W;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> arr[i][j];
        }
    }

    int res = 0;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (arr[i][j] == -1 || arr[i][j] == 0) continue;

            int flag = 0;

            for (int dir = 0; dir < 4; ++dir) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (arr[nx][ny] == -1) continue;

                int from = arr[i][j];
                int to = arr[nx][ny];

                if (abs(from - to) > 1) {
                    cout << -1;
                    return 0;
                }
                if (from < to) flag = 1;
            }
            if (!flag) res++;
        }
    }

    cout << res;

    return 0;
}
