#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N;
vector<int> arr[51];
bool visited[51];

int bfs(int s) {
    queue<pair<int, int>> q;
    q.push({ s, 0 });
    visited[s] = true;
    int ret = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        ret = cnt;

        for (auto n : arr[cur]) {
            if (!visited[n]) {
                visited[n] = true;
                q.push({ n, cnt + 1 });
            }
        }
    }

    return ret;
}

int main() {
    FastIO;

    cin >> N;

    int s, e;
    while (true) {
        cin >> s >> e;
        if (s == -1 && e == -1) break;
        
        arr[s].push_back(e);
        arr[e].push_back(s);
    }

    vector<int> ans;
    int res = 999;

    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        int score = bfs(i);
        if (score <= res) {
            if (score < res) {
                ans.clear();
                res = score;
            }
            ans.push_back(i);
        }
    }

    cout << res << " " << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}