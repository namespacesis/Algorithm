#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

const int N = 4;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int bfs(const string& start, const string& goal) {
    unordered_set<string> visited;
    queue<pair<string, int>> q;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [cur, dist] = q.front(); q.pop();
        if (cur == goal) return dist;

        for (int i = 0; i < 16; ++i) {
            int x = i / 4, y = i % 4;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
                int ni = nx * 4 + ny;
                if (i < ni) {
                    string next = cur;
                    swap(next[i], next[ni]);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, dist + 1});
                    }
                }
            }
        }
    }
}

int main() {
    FastIO;
    string start, goal, line;
    for (int i = 0; i < 4; ++i) {
        cin >> line;
        start += line;
    }
    while (getline(cin, line)) {
        if (!line.empty()) {
            goal += line;
            if (goal.size() == 16) break;
        }
    }

    cout << bfs(start, goal) << endl;

    return 0;
}