#include <iostream>
#include <deque>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define INF 1e9

using namespace std;

struct Node {
    int x, y, cnt;
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

        deque<Node> dq;

        for (int i = 0; i < R; i++) {
            dq.push_front({ i, 0, arr[i][0] });
            visited[i][0] = arr[i][0];
            dq.push_front({ i, C - 1, arr[i][C - 1] });
            visited[i][C - 1] = arr[i][C - 1];
        }

        for (int j = 1; j < C - 1; j++) {
            dq.push_front({ 0, j, arr[0][j] });
            visited[0][j] = arr[0][j];
            dq.push_front({ R - 1, j, arr[R - 1][j] });
            visited[R - 1][j] = arr[R - 1][j];
        }

        while (!dq.empty()) {
            Node cur = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                    int ncnt = cur.cnt + arr[nx][ny];
                    if (ncnt < visited[nx][ny]) {
                        visited[nx][ny] = ncnt;
                        if (arr[nx][ny] == 0) {
                            dq.push_front({ nx, ny, ncnt });
                        }
                        else {
                            dq.push_back({ nx, ny, ncnt });
                        }
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
