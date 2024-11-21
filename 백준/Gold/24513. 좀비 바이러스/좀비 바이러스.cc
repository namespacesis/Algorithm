#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Virus {
    int x, y;
    int num;
    int cnt;
};

int N, M;
int arr[1000][1000];
int visited[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    FastIO;

    cin >> N >> M;

    queue<Virus> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({ i, j, 1, 1 });
                visited[i][j] = 1;
            }
            else if (arr[i][j] == 2) {
                q.push({ i, j, 2, 1 });
                visited[i][j] = 1;
            }
        }
    }

    int res1 = 0, res2 = 0, res3 = 0;

    while (!q.empty()) {
        Virus cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] == 1) res1++;
        else if (arr[cur.x][cur.y] == 2) res2++;
        else if (arr[cur.x][cur.y] == 3) res3++;

        if (arr[cur.x][cur.y] == 3) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (arr[nx][ny] == 0) {
                visited[nx][ny] = cur.cnt + 1;
                arr[nx][ny] = cur.num;
                q.push({ nx, ny, cur.num, cur.cnt + 1 });
            }
            else if (abs(arr[nx][ny] - cur.num) == 1) {
                if (visited[nx][ny] == cur.cnt + 1) {
                    arr[nx][ny] = 3;
                }
            }
        }
    }

    cout << res1 << " " << res2 << " " << res3 << "\n";

    return 0;
}
