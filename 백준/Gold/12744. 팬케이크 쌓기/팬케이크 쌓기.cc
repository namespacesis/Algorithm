#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
string arr;
unordered_map<string, int> um;

bool check(const string& s) {
    for (int i = 0; i < N; i++) {
        if (s[i] != '1' + i || s[N + i] != '+') {
            return false;
        }
    }
    return true;
}

string rev(const string& s, int idx) {
    string res = s;

    reverse(res.begin(), res.begin() + idx + 1);
    reverse(res.begin() + N, res.begin() + N + idx + 1);

    for (int i = N; i <= N + idx; i++) {
        res[i] = (res[i] == '+') ? '-' : '+';
    }

    return res;
}

int bfs() {
    queue<string> q;
    q.push(arr);
    um[arr] = 0;

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if (check(cur)) {
            return um[cur];
        }

        for (int i = 0; i < N; i++) {
            string next = rev(cur, i);

            if (um.find(next) != um.end()) {
                continue;
            }

            um[next] = um[cur] + 1;
            q.push(next);
        }
    }
}

int main() {
    FastIO;

    cin >> N;
    arr.resize(2 * N);

    for (int i = 0; i < N; i++) {
        int size;
        char dir;
        cin >> size >> dir;
        arr[i] = '0' + size;
        arr[N + i] = dir;
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}
