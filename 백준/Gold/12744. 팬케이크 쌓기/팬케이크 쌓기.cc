#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;
using ii = pair<int, int>;

int N;
vector<ii> arr(6);
map<vector<ii>, int> visited;

bool check(const vector<ii>& v) {
    for (int i = 0; i < N; i++) {
        if (i + 1 != v[i].first || 1 != v[i].second) {
            return false;
        }
    }
    return true;
}

vector<ii> rev(vector<ii> v, int idx) {
    reverse(v.begin(), v.begin() + idx + 1);

    for (int i = 0; i <= idx; i++) {
        v[i].second *= -1;
    }

    return v;
}

int bfs() {
    queue<vector<ii>> q;
    q.push(arr);
    visited[arr] = 0;

    while (!q.empty()) {
        vector<ii> cur = q.front();
        q.pop();

        if (check(cur)) {
            return visited[cur];
        }

        for (int i = 0; i < N; i++) {
            vector<ii> next = rev(cur, i);

            if (visited.find(next) != visited.end()) {
                continue;
            }

            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first;

        char dir;
        cin >> dir;
        if (dir == '+') {
            arr[i].second = 1;
        }
        else if (dir == '-') {
            arr[i].second = -1;
        }
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}
