#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M, H;
int sx, sy;
vector<pair<int, int>> v;
int visited[10];
int res;

void dfs(int x, int y, int hp, int cnt) {
    int dist = abs(x - sx) + abs(y - sy);

    if (hp >= dist) {
        res = max(res, cnt);
    }

    for (int i = 0; i < v.size(); i++) {
        int dist = abs(x - v[i].first) + abs(y - v[i].second);

        if (!visited[i] && hp >= dist) {
            visited[i] = true;
            dfs(v[i].first, v[i].second, hp - dist + H, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M >> H;

    int a;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a;
            if (a == 1) {
                sx = i, sy = j;
            }
            else if (a == 2) {
                v.push_back({i, j});
            }
        }
    }

    dfs(sx, sy, M, 0);

    cout << res << "\n";

    return 0;
}
