#include <iostream>
#include <queue>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

struct Node {
    int x, y;
    int cnt;
    bool getFish;
};

int N, M;
char arr[1000][1000];
bool visited[1000][1000][2];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sr, sc;

int bfs() {
    queue<Node> q;
    q.push({ sr, sc, 0, false });
    visited[sr][sc][0] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] == 'H' && cur.getFish == true) {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny][cur.getFish]) continue;

            if (arr[nx][ny] == 'D') continue;

            if (arr[nx][ny] == 'F') {
                visited[nx][ny][1] = true;
                q.push({ nx, ny, cur.cnt + 1, true });
            }
            else {
                visited[nx][ny][cur.getFish] = true;
                q.push({ nx, ny, cur.cnt + 1, cur.getFish });
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

            if (arr[i][j] == 'S') {
                sr = i, sc = j;
            }
        }
    }

    int res = bfs();

    cout << res << endl;

    return 0;
}
