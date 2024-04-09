#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int x;
	int y;
	int cnt;
};

int M;
char arr[2][50];
bool visited[2][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
    queue<Node> q;

    for (int i = 0; i < 2; ++i) {
        if (arr[i][0] == '.') {
            q.push({ i, 0, 1 });
            visited[i][0] = true;
        }
    }

    int minCnt = 999999;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.y == M - 1) {
            minCnt = min(minCnt, cur.cnt);
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 <= nx && nx < 2 && 0 <= ny && ny < M && arr[nx][ny] == '.' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny, cur.cnt + 1 });
            }
        }
    }

    return minCnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M;

    int cnt = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == '.') {
                cnt++;
            }
        }
    }

    int maxPath = bfs();

    cout << cnt - maxPath << "\n";

    return 0;
}
