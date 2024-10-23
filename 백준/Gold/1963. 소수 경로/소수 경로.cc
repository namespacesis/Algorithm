#include <iostream>
#include <string>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int T;
int N, M;
bool visited[10000];

static bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

static int bfs() {
    queue<pair<int, int>> q;
    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == M) {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                string next = to_string(cur);
                next[i] = j + '0';
                if (stoi(next) >= 1000 && !visited[stoi(next)]) {
                    if (!isPrime(stoi(next))) continue;
					visited[stoi(next)] = true;
					q.push({ stoi(next), cnt + 1 });
				}
            }
        }
    }
    return -1;
}

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        memset(visited, false, sizeof(visited));

        cin >> N >> M;

        int res = bfs();

        if (res == -1) cout << "Impossible\n";
		else cout << res << "\n";
    }

    return 0;
}