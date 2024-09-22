#include <iostream>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

char arr[5][5];
bool visited[5][5];
bool check[25];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int res = 0;

bool bfs(int idx) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ idx / 5, idx % 5 });
    visited[idx / 5][idx % 5] = true;

    int cnt = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cnt++;

        if (cnt == 7) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && !visited[nx][ny] && check[nx * 5 + ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
        }
    }

    return false;
}

void dfs(int depth, int idx, int cnt) {
    if (depth == 7) {
        if (cnt >= 4) {
            if (bfs(idx)) res++;
        }
        return;
    }

    for (int i = idx; i < 25; i++) {
        if (check[i]) continue;

        check[i] = true;
        dfs(depth + 1, i, cnt + (arr[i / 5][i % 5] == 'S'));
        check[i] = false;
    }
}

int main() {
    FastIO;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << res << "\n";

    return 0;
}
