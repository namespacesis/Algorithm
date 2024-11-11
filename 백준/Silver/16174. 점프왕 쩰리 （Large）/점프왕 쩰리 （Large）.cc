#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
    int cnt;
};

int N;
int arr[64][64];
bool visited[64][64];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool bfs() {
    queue<Node> q;
    q.push({ 0, 0, arr[0][0]});
    visited[0][0] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == N - 1 && cur.y == N - 1) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i] * cur.cnt;
            int ny = cur.y + dy[i] * cur.cnt;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny, arr[nx][ny]});
        }
    }

    return false;
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    bool res = bfs();

    if (res) cout << "HaruHaru" << "\n";
    else cout << "Hing" << "\n";

    return 0;
}