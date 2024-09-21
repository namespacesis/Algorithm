#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

struct Edge {
    int from;
    int to;
    int len;
    bool operator<(const Edge& e) const {
        return len < e.len;
    }
};

int N, M;
int arr[10][10];
bool visited[10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int parent[7];
vector<Edge> edges;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

void bfs(int x, int y, int id) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    arr[x][y] = id;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (!visited[nx][ny] && arr[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    arr[nx][ny] = id;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

void findBridges() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] > 0) {
                int id = arr[i][j];
                for (int d = 0; d < 4; d++) {
                    int x = i;
                    int y = j;
                    int len = 0;
                    while (true) {
                        x += dx[d];
                        y += dy[d];
                        if (x < 0 || x >= N || y < 0 || y >= M) break;
                        if (arr[x][y] == id) break;
                        if (arr[x][y] > 0) {
                            if (len >= 2) {
                                edges.push_back({ id, arr[x][y], len });
                            }
                            break;
                        }
                        if (arr[x][y] == 0) {
                            len++;
                        }
                    }
                }
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
        }
    }

    int id = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && arr[i][j] == 1) {
                bfs(i, j, id);
                id++;
            }
        }
    }

    for (int i = 1; i < id; i++) {
        parent[i] = i;
    }

    findBridges();

    sort(edges.begin(), edges.end());

    int total = 0;
    int cnt = 0;

    for (auto& edge : edges) {
        int a = getParent(edge.from);
        int b = getParent(edge.to);
        if (a != b) {
            unionParent(a, b);
            total += edge.len;
            cnt++;
        }
    }

    int root = getParent(1);
    bool connected = true;
    for (int i = 2; i < id; i++) {
        if (root != getParent(i)) {
            connected = false;
            break;
        }
    }

    if (connected) {
        cout << total << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}
