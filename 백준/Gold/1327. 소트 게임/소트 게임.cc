#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    string s;
    int cnt;
};

int N, K;
string s;
string ans;
unordered_map<string, bool> visited;

int main() {
    FastIO;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        string tmp;
		cin >> tmp;
		s += tmp;
        ans += to_string(i + 1);
    }

    queue<Node> q;
    q.push({s, 0});
    visited[s] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.s == ans) {
            cout << cur.cnt << "\n";
            return 0;
        }

        for (int i = 0; i <= N - K; i++) {
			string tmp = cur.s;
			reverse(tmp.begin() + i, tmp.begin() + i + K);

			if (!visited[tmp]) {
				visited[tmp] = true;
				q.push({tmp, cur.cnt + 1});
			}
		}
    }

    cout << -1 << "\n";

    return 0;
}
