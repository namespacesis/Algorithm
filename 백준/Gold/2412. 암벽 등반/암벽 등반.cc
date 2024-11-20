#include <iostream>
#include <unordered_map>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define ll long long
using namespace std;

struct Node {
    int x, y;
    int cnt;
};

int N, T;
unordered_map<ll, int> um;
bool visited[50001];

int main() {
    FastIO;

    cin >> N >> T;
    
    int idx = 1;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        ll hash = (ll)a * 1000000 + b;
        um[hash] = idx;
        idx++;
    }

    queue<Node> q;
    q.push({0, 0, 0});
    if (um[0]) {
        visited[um[0]] = true;
    }

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.y == T) {
            cout << cur.cnt << "\n";
            return 0;
        }

        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (i == 0 && j == 0) continue;

                int nx = cur.x + i;
                int ny = cur.y + j;

                if (nx < 0 || nx > 1000000 || ny < 0 || ny > T) continue;

                ll hash = (ll)nx * 1000000 + ny;

                if (!um[hash]) continue;

                int idx = um[hash];

                if (visited[idx]) continue;

                visited[idx] = true;
                q.push({ nx, ny, cur.cnt + 1 });
            }
        }
    }

    cout << -1 << "\n";

    return 0;
}
