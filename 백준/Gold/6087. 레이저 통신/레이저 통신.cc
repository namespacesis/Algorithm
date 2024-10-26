#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
    int dir;
    int cnt;

    bool operator<(const Node& n) const {
        return cnt > n.cnt;
    }
};

int W, H;
char arr[100][100];
int visited[100][100][4];
int sr, sc;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool checkMirror(int dir, int i) {
    if (dir == 0 && i == 1) return false;
	if (dir == 1 && i == 0) return false;
	if (dir == 2 && i == 3) return false;
	if (dir == 3 && i == 2) return false;
	return true;
}

int bfs() {
    priority_queue<Node> q;
    q.push({sr, sc, -1, 0});
    visited[sr][sc][0] = 0;
    visited[sr][sc][1] = 0;
    visited[sr][sc][2] = 0;
    visited[sr][sc][3] = 0;

    while (!q.empty()) {
        Node cur = q.top();
        q.pop();

        if (arr[cur.x][cur.y] == 'C') {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++) {
            if (!checkMirror(cur.dir, i)) continue;
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 > nx || nx >= H || 0 > ny || ny >= W) continue;

            if (arr[nx][ny] == '*') continue;

            int cnt = cur.cnt;
            if (cur.dir != -1 && cur.dir != i) cnt++;

            if (cnt < visited[nx][ny][i]) {
				visited[nx][ny][i] = cnt;
				q.push({nx, ny, i, cnt});
			}
        }
    }
}

int main() {
    FastIO;

    cin >> W >> H;

    bool check = false;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'C' && !check) {
                sr = i;
                sc = j;
                check = true;
                arr[i][j] = '.';
            }
            fill(visited[i][j], visited[i][j] + 4, 1e9);
        }
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}