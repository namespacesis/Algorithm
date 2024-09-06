#include <iostream>
#include <string>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M;
int arr[100][100];
int visited[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct Node {
    int x;
    int y;
    int cnt;
    
    bool operator < (const Node& n) const {
        return cnt > n.cnt;
    }
};

int bfs() {
    priority_queue<Node> pq;
    pq.push({ 0, 0, 0 });
    visited[0][0] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.x == N - 1 && cur.y == M - 1) {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (visited[nx][ny] > cur.cnt) {
                    visited[nx][ny] = cur.cnt;
                    if (arr[nx][ny] == 0) {
                        pq.push({ nx, ny, cur.cnt });
                    }
                    else {
                        pq.push({ nx, ny, cur.cnt + 1 });
                    }
                }
            }
        }
    }
}

int main() {
    FastIO;

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            arr[i][j] = line[j] - '0';
            visited[i][j] = 1e9;
        }
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}
