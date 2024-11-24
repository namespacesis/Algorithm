#include <iostream>
#include <string>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
};

int H, W;
int arr[1000][1000];
const int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
const int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
queue<Node> q;

static int bfs() {
    int ret = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node cur = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

                if (arr[nx][ny] > 0) {
                    arr[nx][ny]--;
                    if (arr[nx][ny] == 0) {
                        q.push({ nx, ny });
                    }
                }
            }
        }
        ret++;
    }
    
    return ret;
}

int main() {
    FastIO;

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            if (s[j] == '.') {
                arr[i][j] = 0;
                q.push({ i, j });
            }
            else {
                arr[i][j] = s[j] - '0';
            }
        }
    }

    int res = bfs() - 1;

    cout << res << "\n";

    return 0;
}
