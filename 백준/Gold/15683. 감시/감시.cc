#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct CCTV {
    int x, y, type;
};

int N, M;
int arr[8][8];
vector<CCTV> cctv;
int res = 64;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void watch(int board[8][8], int x, int y, int dir) {
    dir %= 4;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        
        if (x < 0 || y < 0 || x >= N || y >= M || board[x][y] == 6) return;
        
        if (board[x][y] == 0) {
            board[x][y] = -1; 
        }
    }
}

void dfs(int cctv_idx, int board[8][8]) {
    if (cctv_idx == cctv.size()) {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (board[i][j] == 0) count++;
            }
        }
        res = min(res, count);
        return;
    }

    int x = cctv[cctv_idx].x;
    int y = cctv[cctv_idx].y;
    int type = cctv[cctv_idx].type;

    for (int dir = 0; dir < 4; ++dir) {
        int backup[8][8];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                backup[i][j] = board[i][j];
            }
        }

        if (type == 1) {
            watch(backup, x, y, dir);
        } else if (type == 2) {
            watch(backup, x, y, dir);
            watch(backup, x, y, dir + 2);
        } else if (type == 3) {
            watch(backup, x, y, dir);
            watch(backup, x, y, dir + 1);
        } else if (type == 4) {
            watch(backup, x, y, dir);
            watch(backup, x, y, dir + 1);
            watch(backup, x, y, dir + 2);
        } else if (type == 5) {
            watch(backup, x, y, dir);
            watch(backup, x, y, dir + 1);
            watch(backup, x, y, dir + 2);
            watch(backup, x, y, dir + 3);
        }

        dfs(cctv_idx + 1, backup);
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5) {
                cctv.push_back({i, j, arr[i][j]});
            }
        }
    }

    dfs(0, arr);

    cout << res << endl;

    return 0;
}