#include <iostream>
#include <queue>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
};

int N;
char arr[1002][1002];
bool visited[1002][1002];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int res1 = 0;
int res2 = 1e9;

void bfs(int x, int y) {
    queue<Node> q;
    q.push({ x, y });
    visited[x][y] = true;

    int ret1 = 1;
    int ret2 = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx > N + 1 || ny > N + 1) continue;

            if (arr[nx][ny] == '.') ret2++;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] == '#') {
                ret1++;
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    if (ret1 > res1) {
        res1 = ret1;
        res2 = ret2;
    }
    else if (ret1 == res1) {
		res2 = min(res2, ret2);
	}

    return;
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i <= N + 1; i++) {
		arr[0][i] = arr[N + 1][i] = '.';
        arr[i][0] = arr[i][N + 1] = '.';
	}

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == '#' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << res1 << " " << res2 << "\n";

    return 0;
}
