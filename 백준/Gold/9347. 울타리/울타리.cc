#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define INF 1e9

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;

    bool operator<(const Node& t) const {
        return cnt > t.cnt;
    }
};

int T;
int R, C;
int arr[1000][1000];
int visited[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> R >> C;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> arr[i][j];
                visited[i][j] = INF;
            }
        }

        priority_queue<Node> pq;

        for (int i = 0; i < R; i++) {
            pq.push({ i, 0, arr[i][0] });
            visited[i][0] = arr[i][0];
            pq.push({ i, C - 1, arr[i][C - 1] });
            visited[i][C - 1] = arr[i][C - 1];
        }

        for (int j = 1; j < C - 1; j++) {
            pq.push({ 0, j, arr[0][j] });
            visited[0][j] = arr[0][j];
            pq.push({ R - 1, j, arr[R - 1][j] });
            visited[R - 1][j] = arr[R - 1][j];
        }

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();

            if (cur.cnt > visited[cur.x][cur.y]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                    int ncnt = cur.cnt + arr[nx][ny];
                    if (ncnt < visited[nx][ny]) {
                        visited[nx][ny] = ncnt;
                        pq.push({ nx, ny, ncnt });
                    }
                }
            }
        }

        int res1 = 0;
        int res2 = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!arr[i][j]) {
                    if (res1 < visited[i][j]) {
                        res1 = visited[i][j];
                        res2 = 1;
                    }
                    else if (res1 == visited[i][j]) {
						res2++;
					}
                }
            }
        }

        cout << res1 << " " << res2 << "\n";
    }

    return 0;
}
