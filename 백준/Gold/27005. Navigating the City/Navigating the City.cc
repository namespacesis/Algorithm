#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

struct Node {
    int x;
    int y;
    string s;
};

int N, E;
char arr[59][79];
bool visited[59][79];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int sr, sc, er, ec;
char dir[4] = {'S', 'N', 'E', 'W'};

string bfs() {
    queue<Node> q;
    q.push({sr, sc, ""});
    visited[sr][sc] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] == 'E') {
            return cur.s;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (arr[nx][ny] == '-' || arr[nx][ny] == '|') {
                nx += dx[i];
                ny += dy[i];
                if (0 > nx || nx > 58 || 0 > ny || ny > 78) continue;
                if (visited[nx][ny]) continue;

                visited[nx][ny] = true;
                q.push({nx, ny, cur.s + dir[i]});
            }
        }
    }
}

int main() {
    FastIO;

    cin >> N >> E;

    for (int i = 0; i < N * 2 - 1; i++) {
        for (int j = 0; j < E * 2 - 1; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            else if (arr[i][j] == 'E') {
                er = i;
                ec = j;
            }
        }
    }

    string ret = bfs();

    char r1 = ret[0];
    int r2 = 1;

    for (int i = 1; i < ret.length(); i++) {
        if (ret[i] == r1) {
            r2++;
        }
        else {
            cout << r1 << " " << r2 << endl;
            r1 = ret[i];
            r2 = 1;
        }
    }

    cout << r1 << " " << r2 << endl;

    return 0;
}