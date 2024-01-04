#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int N, M;
int K;
int arr[1002][1002];
int dx[4] = { 1, -1, 0, 0, };
int dy[4] = { 0, 0, 1, -1 };
priority_queue<tuple<int, int, int>> pq;
int visited[1002][1002];
vector<pair<int, int>> res;

void bfs() {
    while (!pq.empty()) {
        int val, cx, cy;
        tie(val, cx, cy) = pq.top();
        pq.pop();

        res.push_back({ cx, cy });
        cout << cx << " " << cy << "\n";
        if (res.size() == K) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (1 <= nx && nx <= N && 1 <= ny && ny <= M && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                pq.push({ arr[nx][ny], nx, ny });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 || i == N || j == 1 || j == M) {
                pq.push({ arr[i][j], i, j });
                visited[i][j] = 1;
            }
        }
    }

    bfs();

    return 0;
}