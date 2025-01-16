#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int x, y;
    int cnt;
};

int N, M;
char arr[300][300];
bool visited[300][300];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
unordered_map<char, vector<pair<int, int>>> um;
int sr, sc;

int bfs() {
    queue<Node> q;
    q.push({ sr, sc, 0 });
    visited[sr][sc] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] == '=') {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny] || arr[nx][ny] == '#') continue;

            visited[nx][ny] = true;

            if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'Z') {
                for (auto& p : um[arr[nx][ny]]) {
                    if (nx == p.first && ny == p.second) continue;
                    q.push({ p.first, p.second, cur.cnt + 1 });
                }
            }
            else {
                q.push({ nx, ny, cur.cnt + 1 });
            }
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '@') {
                sr = i;
                sc = j;
            }
            else if ('A' <= arr[i][j] && arr[i][j] <= 'Z') {
                um[arr[i][j]].push_back({ i, j });
            }
        }
    }

    int res = bfs();

    cout << res << endl;

    return 0;
}