#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
char arr[2000][2000];
bool visited[2000][2000];
int dx[7] = { -1, -1, 0, 0, 1, -1, 1 };
int dy[7] = { -1, 1, -1, 1, -1, 0, 1 };
int sx, sy;
int res;

struct Node {
    int x;
    int y;
};

void bfs() {
    queue<Node> q;
    q.push({ sx, sy });
    visited[sx][sy] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 7; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] == '.') {
                visited[nx][ny] = true;
                res++;
                q.push({ nx, ny });
            }
        }
    }
}

int main() {
    FastIO;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'F') {
                sx = i, sy = j;
            }
        }
    }

    bfs();

    cout << res << "\n";

    return 0;
}
