#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 51
#define INF 1e9

using namespace std;

struct Node {
	int x;
	int y;
	int w;

	bool operator<(const Node& temp) const{
		return w > temp.w;
	}
};

int N, K, M;
int n, x, y, nx, ny;
int nx1, ny1, nx2, ny2;
bool map[MAXN][MAXN];
int dist[MAXN][MAXN];
pair<int, int> path[MAXN][MAXN];
priority_queue<Node> pq;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int findDirection(int x1, int y1, int x2, int y2) {
	if (y2 - y1 > 0) return 0;
	else if (x2 - x1 > 0) return 1;
	else if (y2 - y1 < 0) return 2;
	return 3;
}

void bfs() {
    pq.push({ nx1, ny1, 0 });
    dist[nx1][ny1] = 0;

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int cur_w = pq.top().w;
        pq.pop();

        if (dist[x][y] != cur_w) continue;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;

            int next_w;

            if (map[nx][ny]) next_w = cur_w + K;
            else next_w = cur_w + 1;

            if (dist[nx][ny] > next_w) {
                dist[nx][ny] = next_w;
                path[nx][ny] = { x,y };
                pq.push({ nx,ny,next_w });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }

    cin >> nx1 >> ny1 >> nx2 >> ny2;
    cin >> K >> M;

    while (M--) {
        cin >> n >> x >> y;

        for (int i = 0; i < n - 1; i++) {
            cin >> nx >> ny;

            int d = findDirection(x, y, nx, ny);

            while (x != nx || y != ny) {
                map[x][y] = true;
                x += dx[d];
                y += dy[d];
            }
            map[x][y] = true;
        }
    }

    bfs();

    cout << dist[nx2][ny2] + 1 << "\n";

    vector<pair<int, int>> trace;
    trace.push_back({ nx2, ny2 });

    pair<int, int> tmp = path[nx2][ny2];
    int dir = findDirection(nx2, ny2, tmp.first, tmp.second);
    nx2 = tmp.first;
    ny2 = tmp.second;

    while (nx2 != nx1 || ny2 != ny1) {
        pair<int, int> tmp = path[nx2][ny2];
        int tmp_dir = findDirection(nx2, ny2, tmp.first, tmp.second);

        if (dir != tmp_dir) {
            dir = tmp_dir;
            trace.push_back({ nx2, ny2 });
        }

        nx2 = tmp.first;
        ny2 = tmp.second;
    }
    trace.push_back({ nx1, ny1 });
    reverse(trace.begin(), trace.end());
    cout << trace.size() << " ";

    for (int i = 0; i < trace.size(); i++) {
        cout << trace[i].first << " " << trace[i].second << " ";
    }

    return 0;
}