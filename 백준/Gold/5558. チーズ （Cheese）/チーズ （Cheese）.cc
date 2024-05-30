#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAXN 1000

using namespace std;

struct Node {
    int x, y, cnt;
};

int H, W, N;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int sx, int sy, char target) {
    queue<Node> q;
    q.push({ sx, sy, 0 });
    memset(visited, false, sizeof(visited));
    visited[sx][sy] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (grid[cur.x][cur.y] == target) {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 <= nx && nx < H && 0 <= ny && ny < W && !visited[nx][ny] && grid[nx][ny] != 'X') {
                visited[nx][ny] = true;
                q.push({ nx, ny, cur.cnt + 1 });
            }
        }
    }

    return -1;
}

int main() {
    fastIO;
    cin >> H >> W >> N;

    int sx, sy;
    vector<pair<int, int>> cheesePositions(N + 1);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if (grid[i][j] >= '1' && grid[i][j] <= '9') {
                cheesePositions[grid[i][j] - '0'] = { i, j };
            }
        }
    }

    int total_time = 0;
    int current_x = sx, current_y = sy;

    for (int i = 1; i <= N; i++) {
        int target_x = cheesePositions[i].first;
        int target_y = cheesePositions[i].second;
        int time_to_cheese = bfs(current_x, current_y, '0' + i);
        total_time += time_to_cheese;
        current_x = target_x;
        current_y = target_y;
    }

    cout << total_time << "\n";
    return 0;
}
