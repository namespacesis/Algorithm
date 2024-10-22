#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;
    int key;
};

int N, M;
char arr[50][50];
bool visited[50][50][1 << 6];
int sr;
int sc;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
    queue<Node> q;
    q.push({ sr, sc, 0, 0 });
    visited[sr][sc][0] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] == '1') {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny][cur.key] || arr[nx][ny] == '#') continue;

            if (arr[nx][ny] == '.' || arr[nx][ny] == '1') {
                visited[nx][ny][cur.key] = true;
                q.push({ nx, ny, cur.cnt + 1, cur.key });
            }
            else if ('a' <= arr[nx][ny] && arr[nx][ny] <= 'f') {
                int key = cur.key | (1 << (arr[nx][ny] - 'a'));
                visited[nx][ny][key] = true;
                q.push({ nx, ny, cur.cnt + 1, key });
            }
            else if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'F') {
                if (cur.key & (1 << (arr[nx][ny] - 'A'))) {
                    visited[nx][ny][cur.key] = true;
                    q.push({ nx, ny, cur.cnt + 1, cur.key });
                }
            }
        }
    }
    
    return -1;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == '0') {
                sr = i;
                sc = j;
                arr[i][j] = '.';
            }
        }
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}