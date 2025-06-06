#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

const int N = 4;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int str2mask(const string& s) {
    int mask = 0;
    for (int i = 0; i < 16; ++i) {
        if (s[i] == 'L') mask |= (1 << i);
    }
    return mask;
}

int bfs(int start, int goal) {
    vector<bool> visited(1 << 16, false);
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

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
                    int next = cur;
                    int bi = (cur >> i) & 1, bni = (cur >> ni) & 1;
                    if (bi != bni) {
                        next ^= (1 << i);
                        next ^= (1 << ni);
                        if (!visited[next]) {
                            visited[next] = true;
                            q.push({next, dist + 1});
                        }
                    }
                }
            }
        }
    }
    return -1;
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
    int start_mask = str2mask(start);
    int goal_mask = str2mask(goal);
    cout << bfs(start_mask, goal_mask) << endl;

    return 0;
}