#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x;
    int y;
    int t;
    char color;
};

int N, M;
int G, R;
int arr[50][50];
int visited[50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;
int temp[50][50];
int temp2[50][50];
int visited2[50][50];
int res = 0;

int bfs() {
    queue<Node> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 3) {
                q.push({ i, j, 1, 'G' });
            }
            else if (temp[i][j] == 4) {
                q.push({ i, j, 1, 'R' });
            }
        }
    }
    int cnt = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (temp[cur.x][cur.y] == 5) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (cur.color == 'G') {
                if (temp[nx][ny] == 1 || temp[nx][ny] == 2) {
                    temp[nx][ny] = 3;
                    visited[nx][ny] = cur.t + 1;
                    q.push({ nx, ny, cur.t + 1, 'G' });
                }
                else if (temp[nx][ny] == 4 && visited[nx][ny] == cur.t + 1) {
                    temp[nx][ny] = 5;
                    cnt++;
                }
            }
            else if (cur.color == 'R') {
                if (temp[nx][ny] == 1 || temp[nx][ny] == 2) {
                    temp[nx][ny] = 4;
                    visited[nx][ny] = cur.t + 1;
                    q.push({ nx, ny, cur.t + 1, 'R' });
                }
                else if (temp[nx][ny] == 3 && visited[nx][ny] == cur.t + 1) {
                    temp[nx][ny] = 5;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void dfs(int Gcnt, int Rcnt, int idx) {
    if (Gcnt == G && Rcnt == R) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp2[i][j] = temp[i][j];
                visited2[i][j] = visited[i][j];
            }
        }
        res = max(res, bfs());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp[i][j] = temp2[i][j];
                visited[i][j] = visited2[i][j];
            }
        }
        return;
    }

    if (idx == v.size()) return;

    for (int i = idx; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;

        if (visited[x][y] == 0) {
            visited[x][y] = 1;
            if (Gcnt + 1 <= G) {
                temp[x][y] = 3;
                dfs(Gcnt + 1, Rcnt, i + 1);
            }
            if (Rcnt + 1 <= R) {
                temp[x][y] = 4;
                dfs(Gcnt, Rcnt + 1, i + 1);
            }
            temp[x][y] = arr[x][y];
            visited[x][y] = 0;
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M >> G >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            temp[i][j] = arr[i][j];
            if (arr[i][j] == 2) {
                v.push_back({ i, j });
            }
        }
    }

    dfs(0, 0, 0);

    cout << res << "\n";

    return 0;
}
