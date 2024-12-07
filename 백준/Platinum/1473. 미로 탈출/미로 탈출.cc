#include <iostream>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

struct Node {
    int x, y;
    int rBit, cBit;
};

int N, M;
char arr[7][7];
int visited[1 << 7][1 << 7][7][7];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool canMove(char from, char to, int dir) {
    if (dir == 0 || dir == 1) {
        if (from == 'A' || from == 'D') {
            return to == 'A' || to == 'D';
        }
        else return false;
    }
    else {
        if (from == 'A' || from == 'C') {
            return to == 'A' || to == 'C';
        }
        else return false;
    }
}

char getRoomType(int rBit, int cBit, int x, int y) {
    bool isTurn = ((rBit & (1 << x)) == 0) ^ ((cBit & (1 << y)) == 0);
    char room = arr[x][y];
    if (!isTurn) return room;
    if (room == 'A' || room == 'B') return room;
    if (room == 'C') return 'D';
    if (room == 'D') return 'C';
}

int bfs() {
    queue<Node> q;
    q.push({ 0, 0, 0, 0 });
    visited[0][0][0][0] = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int x = cur.x, y = cur.y;
        int rBit = cur.rBit, cBit = cur.cBit;
        int curDistance = visited[rBit][cBit][x][y];

        if (x == N - 1 && y == M - 1) {
            return curDistance;
        }

        char currentRoom = getRoomType(rBit, cBit, x, y);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            char nextRoom = getRoomType(rBit, cBit, nx, ny);
            if (!canMove(currentRoom, nextRoom, i)) continue;

            if (visited[rBit][cBit][nx][ny] == -1) {
                visited[rBit][cBit][nx][ny] = curDistance + 1;
                q.push({ nx, ny, rBit, cBit });
            }
        }

        int newRBit = rBit ^ (1 << x);
        int newCBit = cBit ^ (1 << y);

        if (visited[newRBit][newCBit][x][y] == -1) {
            visited[newRBit][newCBit][x][y] = curDistance + 1;
            q.push({ x, y, newRBit, newCBit });
        }
    }

    return -1;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    memset(visited, -1, sizeof(visited));

    cout << bfs() << endl;

    return 0;
}
