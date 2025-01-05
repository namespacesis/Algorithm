#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int x, y;
    int cnt;

    bool operator<(const Node& n) const {
        return cnt > n.cnt;
    }
};

int N, M;
int arr[2002][2002];
bool visited[2002][2002];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int dijkstra() {
    priority_queue<Node> pq;
    pq.push({ N + 1, 0, 0 });
    visited[N + 1][0] = true;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.x == 0 && cur.y == M + 1) {
            return cur.cnt;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx > N + 1 || ny > M + 1) continue;

            if (nx == 1 && ny == 1) continue;
            if (nx == N && ny == M) continue;

            if (visited[nx][ny]) continue;

            int ncnt = cur.cnt + !(arr[nx][ny]);

            visited[nx][ny] = true;
            pq.push({ nx, ny, ncnt });
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 2; i <= N + 1; i++) arr[i][0] = 1;
    for (int i = 1; i <= M - 1; i++) arr[N + 1][i] = 1;
    for (int i = 2; i <= M + 1; i++) arr[0][i] = 1;
    for (int i = 1; i <= N - 1; i++) arr[i][M + 1] = 1;

    int res = dijkstra();

    cout << res << endl;

    return 0;
}
