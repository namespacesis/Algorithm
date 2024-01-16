#include <iostream>

using namespace std;

bool arr[10][10];
bool visited1[20];
bool visited2[20];
int res[2];
int S;

void dfs(int cnt, int x, int y, int color) {
    if (x >= S) {
        y++;
        if (x % 2 == 0) x = 1;
        else x = 0;
    }
    if (y >= S) {
        if (cnt > res[color])
            res[color] = cnt;
        return;
    }

    if (arr[y][x] && !visited1[x + y + 1] && !visited2[x - y + S]) {
        visited1[x + y + 1] = true;
        visited2[x - y + S] = true;
        dfs(cnt + 1, x + 2, y, color);
        visited1[x + y + 1] = false;
        visited2[x - y + S] = false;
    }
    dfs(cnt, x + 2, y, color);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> S;

    for (int i = 0; i < S; i++)
        for (int j = 0; j < S; j++)
            cin >> arr[i][j];

    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);

    cout << res[0] + res[1] << '\n';
}