#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

struct Point {
    int x;
    int y;
    int percent;
};

int N;
int arr[499][499];
int res = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
Point moveDir[4][9] = {
    {{-1, 1, 1}, {1, 1, 1},
    {-2, 0, 2}, {2, 0, 2},
    {-1, 0, 7}, {1, 0, 7},
    {-1, -1, 10}, {1, -1, 10},
    {0, -2, 5}},
    {{-1, -1, 1}, {-1, 1, 1},
    {0, -2, 2}, {0, 2, 2},
    {0, -1, 7}, {0, 1, 7},
    {1, -1, 10}, {1, 1, 10},
    {2, 0, 5}},
    {{-1, -1, 1}, {1, -1, 1},
    {-2, 0, 2}, {2, 0, 2},
    {-1, 0, 7}, {1, 0, 7},
    {-1, 1, 10}, {1, 1, 10},
    {0, 2, 5}},
    {{1, -1, 1}, {1, 1, 1},
    {0, -2, 2}, {0, 2, 2},
    {0, -1, 7}, {0, 1, 7},
    {-1, -1, 10}, {-1, 1, 10},
    {-2, 0, 5}}
};

void solve() {
    int dist = 1;
    int dir = 0;
    int x = N / 2;
    int y = N / 2;

    while (true) {
        for (int step = 0; step < 2; step++) {
            for (int i = 0; i < dist; i++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                x = nx;
                y = ny;

                int sand = arr[nx][ny];
                arr[nx][ny] = 0;

                int temp = sand;

                for (int j = 0; j < 9; j++) {
                    int mx = nx + moveDir[dir][j].x;
                    int my = ny + moveDir[dir][j].y;
                    int mSand = sand * moveDir[dir][j].percent / 100;

                    if (0 <= mx && mx < N && 0 <= my && my < N) {
                        arr[mx][my] += mSand;
                    }
                    else {
                        res += mSand;
                    }

                    temp -= mSand;
                }

                int ax = nx + dx[dir];
                int ay = ny + dy[dir];

                if (0 <= ax && ax < N && 0 <= ay && ay < N) {
                    arr[ax][ay] += temp;
                }
                else {
                    res += temp;
                }

                if (x == 0 && y == 0) return;
            }
            dir = (dir + 1) % 4;
        }
        dist++;
    }
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    solve();

    cout << res << "\n";

    return 0;
}
