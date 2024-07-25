#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M;
int TG, TB, X, B;
char arr[1000][1000];
int visited[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;

struct Virus {
    int x;
    int y;
    int t;

    bool operator<(const Virus& v) const {
        return t > v.t;
    }
};

int main() {
    FastIO;

    priority_queue<Virus> pq;

    cin >> N >> M;

    cin >> TG >> TB >> X >> B;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            arr[i][j] = line[j];

            if (arr[i][j] == '*') {
                visited[i][j] = 1;
                cnt++;
                pq.push({ i, j, 0 });
            }
        }
    }

    while (!pq.empty()) {
        Virus cur = pq.top();
        pq.pop();

        if (cur.t > TG) break;

        if (visited[cur.x][cur.y] == 2) {
            visited[cur.x][cur.y] = 1;
            cnt++;
        }

        if (cur.t == TG) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] == '.') {
                visited[nx][ny] = 1;
                cnt++;
                pq.push({ nx, ny, cur.t + 1 });
            }

            else if (arr[nx][ny] == '#') {
                visited[nx][ny] = 2;
                pq.push({ nx, ny, cur.t + 1 + TB });
            }
        }
    }

    if (cnt == N * M) {
        cout << -1 << "\n";
    }

    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] != 1) {
                    cout << i + 1 << " " << j + 1 << "\n";
                }
            }
        }
    }

    return 0;
}
