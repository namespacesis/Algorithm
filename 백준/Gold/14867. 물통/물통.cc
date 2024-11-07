#include <iostream>
#include <queue>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define ll long long

using namespace std;

struct Bottle {
    int x, y;
    int cnt;
};

int a, b, c, d;
unordered_map<ll, bool> visited;

ll makeHash(int x, int y) {
    return (ll)x * 1000000 + y;
}

int bfs() {
    queue<Bottle> q;
    q.push({0, 0, 0});
    visited[0] = true;

    while (!q.empty()) {
        Bottle cur = q.front();
        q.pop();

        if (cur.x == c && cur.y == d) {
            return cur.cnt;
        }

        if (visited.find(makeHash(a, cur.y)) == visited.end()) {
			visited[makeHash(a, cur.y)] = true;
			q.push({ a, cur.y, cur.cnt + 1 });
		}

        if (visited.find(makeHash(cur.x, b)) == visited.end()) {
			visited[makeHash(cur.x, b)] = true;
			q.push({ cur.x, b, cur.cnt + 1 });
		}

        if (visited.find(makeHash(0, cur.y)) == visited.end()) {
            visited[makeHash(0, cur.y)] = true;
            q.push({ 0, cur.y, cur.cnt + 1 });
        }

        if (visited.find(makeHash(cur.x, 0)) == visited.end()) {
			visited[makeHash(cur.x, 0)] = true;
			q.push({ cur.x, 0, cur.cnt + 1 });
		}

        if (cur.x <= b - cur.y) {
            if (visited.find(makeHash(0, cur.y + cur.x)) == visited.end()) {
				visited[makeHash(0, cur.y + cur.x)] = true;
				q.push({ 0, cur.y + cur.x, cur.cnt + 1 });
			}
        }
        else {
            if (visited.find(makeHash(cur.x - (b - cur.y), b)) == visited.end()) {
				visited[makeHash(cur.x - (b - cur.y), b)] = true;
				q.push({ cur.x - (b - cur.y), b, cur.cnt + 1 });
			}
        }

        if (cur.y <= a - cur.x) {
            if (visited.find(makeHash(cur.y + cur.x, 0)) == visited.end()) {
                visited[makeHash(cur.y + cur.x, 0)] = true;
                q.push({ cur.y + cur.x, 0, cur.cnt + 1 });
            }
        }
        else {
            if (visited.find(makeHash(a, cur.y - (a - cur.x))) == visited.end()) {
                visited[makeHash(a, cur.y - (a - cur.x))] = true;
                q.push({ a, cur.y - (a - cur.x), cur.cnt + 1 });
            }
        }
    }

    return -1;
}

int main() {
    FastIO;

    cin >> a >> b >> c >> d;

    int res = bfs();

    cout << res << "\n";

    return 0;
}
