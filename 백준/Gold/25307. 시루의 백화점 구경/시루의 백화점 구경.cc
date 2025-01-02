#include <bits/stdc++.h>

#define FAST_IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;

struct Node {
    int x, y;
    int cnt;
};

int N, M, K;
int arr[2000][2000];
bool visited[2000][2000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<Node> q;
int sr, sc;

void preProcess() {
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.cnt == K) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny, cur.cnt + 1});
        }
    }
}

int bfs() {
    q.push({sr, sc, 0});
    visited[sr][sc] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] == 2) {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            q.push({nx, ny, cur.cnt + 1});
        }
    }

    return -1;
}

int main() {
    FAST_IO;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 4) {
                sr = i;
                sc = j;
            }
            if (arr[i][j] == 3) {
                visited[i][j] = true;
                q.push({i, j, 0});
            }
        }
    }

    preProcess();

    int res = bfs();

    cout << res << endl;

    return 0;
}