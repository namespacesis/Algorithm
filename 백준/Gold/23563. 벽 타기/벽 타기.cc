#include <iostream>
#include <deque>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int x, y;
    int cnt;
};

int H, W;
char arr[500][500];
bool checkWall[500][500];
int visited[500][500];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sr, sc;
int er, ec;

void findWall() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (arr[i][j] == '#') continue;

            bool check = false;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

                if (arr[nx][ny] == '#') {
                    check = true;
                    break;
                }
            }
            checkWall[i][j] = check;
        }
    }
}

void zeroOneBfs() {
    deque<Node> dq;
    dq.push_back({ sr, sc, 0 });
    visited[sr][sc] = 0;

    while (!dq.empty()) {
        Node cur = dq.front();
        dq.pop_front();

        if (arr[cur.x][cur.y] == 'E') {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

            if (arr[nx][ny] == '#') continue;

            int cost = 1;

            if (checkWall[cur.x][cur.y] && checkWall[nx][ny]) {
                cost = 0;
            }

            int ncnt = cur.cnt + cost;

            if (visited[nx][ny] <= ncnt) continue;

            visited[nx][ny] = ncnt;

            if (cost == 0) {
                dq.push_front({ nx, ny, ncnt });
            }
            else {
                dq.push_back({ nx, ny, ncnt });
            }
        }
    }
}

int main() {
    FastIO;

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            else if (arr[i][j] == 'E') {
				er = i;
				ec = j;
			}
            visited[i][j] = 999999;
        }
    }

    findWall();

    zeroOneBfs();

    int res = visited[er][ec];

    cout << res << endl;

    return 0;
}