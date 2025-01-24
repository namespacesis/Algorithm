#include <iostream>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;
};

int visited[8][8];
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int sr, sc;
int er, ec;

int main() {
    FastIO;

    cin >> sr >> sc >> er >> ec;
    sr--, sc--, er--, ec--;

    memset(visited, 0x3f, sizeof(visited));

    queue<Node> q;
    q.push({ sr, sc, 0 });
    visited[sr][sc] = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == er && cur.y == ec) {
            cout << cur.cnt << endl;
            break;
        }

        for (int i = 0; i < 8; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
			if (visited[nx][ny] < cur.cnt + 1) continue;

			visited[nx][ny] = cur.cnt + 1;
			q.push({ nx, ny, cur.cnt + 1 });
		}
    }

    return 0;
}