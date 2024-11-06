#include <iostream>
#include <queue>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
};

int N, M, P;
int mov[10];
int arr[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int res[10];
vector<queue<Node>> q(10);

void bfs(int idx) {
    int steps = mov[idx];
    while (steps-- > 0 && !q[idx].empty()) {
        int sz = q[idx].size();
        for (int i = 0; i < sz; i++) {
            Node cur = q[idx].front();
            q[idx].pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (arr[nx][ny] != 0) continue;

                arr[nx][ny] = idx;
                res[idx]++;
                q[idx].push({ nx, ny });
            }
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M >> P;

    for (int i = 1; i <= P; i++) {
        cin >> mov[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;
            if (x == '.') arr[i][j] = 0;
            else if (x == '#') arr[i][j] = -1;
            else {
                int player = x - '0';
                arr[i][j] = player;
                q[player].push({ i, j });
                res[player]++;
            }
        }
    }

    bool expanded = true;
    while (expanded) {
        expanded = false;
        for (int i = 1; i <= P; i++) {
            if (!q[i].empty()) {
                bfs(i);
                expanded = true;
            }
        }
    }

    for (int i = 1; i <= P; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}
