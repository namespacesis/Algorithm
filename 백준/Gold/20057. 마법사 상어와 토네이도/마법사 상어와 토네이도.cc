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
    int movcnt = 0;
    int cnt = 0;
    int dir = 0;
    int x = N / 2;
    int y = N / 2;

    while (true) {
        if (x == 0 && y == 0) {
            break;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;

        int sand = arr[nx][ny];
        arr[nx][ny] = 0;

        int temp = sand;

        for (int i = 0; i < 9; i++) {
            int mx = nx + moveDir[dir][i].x;
            int my = ny + moveDir[dir][i].y;
            int mSand = sand * moveDir[dir][i].percent / 100;

            if (0 <= mx && mx < N && 0 <= my && my < N) {
                arr[mx][my] += mSand;
            }
            else {
                res += mSand;
            }

            temp -= mSand;
        }

        if (0 <= nx + dx[dir] && nx + dx[dir] < N && 0 <= ny + dy[dir] && ny + dy[dir] < N) {
            arr[nx + dx[dir]][ny + dy[dir]] += temp;
        }
        else {
            res += temp;
        }

        cnt++;
        movcnt++;
        
        if (movcnt == dist) {
            dir = (dir + 1) % 4;
            movcnt = 0;
        }

        if (cnt == dist * 2 && dist != N - 1) {
            cnt = 0;
            dist++;
        }
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
