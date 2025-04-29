#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N, L;
vector<int> stations[100001];
vector<int> routes[100001];
bool visited[100001];
int s, e;

int bfs() {
    int ret = 1e9;

    queue<pair<int, int>> q;

    for (auto station : stations[s]) {
        q.push({ station, 0 });
        visited[station] = true;
    }

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (auto next : routes[cur]) {
            if (next == e) {
                ret = min(ret, cnt);
                break;
            }
            else {
                for (auto station : stations[next]) {
                    if (visited[station]) continue;
                    visited[station] = true;
                    q.push({ station, cnt + 1 });
                }
            }
        }
    }

    if (ret == 1e9) ret = -1;

    return ret;
}

int main() {
    FastIO;

    cin >> N >> L;

    int x;

    for (int i = 1; i <= L; i++) {
        while (true) {
            cin >> x;
            if (x == -1) break;
            stations[x].push_back(i);
            routes[i].push_back(x);
        }
    }

    cin >> s >> e;

    int res = bfs();

    cout << res << endl;

    return 0;
}
