#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N, K;
int M;
int res = -1;
unordered_map<string, bool> visited;

void bfs() {
    queue<pair<int, int>> q;
    string s = to_string(N);
    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            string temp = s;
            if (i == 0 && temp[j] == '0') continue;
            swap(temp[i], temp[j]);
            if (visited[temp + '1']) continue;
            visited[temp + '1'] = true;
            q.push({ stoi(temp), 1 });
        }
    }

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cnt == K) {
            res = max(res, cur);
            continue;
        }

        string temp = to_string(cur);
        for (int i = 0; i < M - 1; i++) {
			for (int j = i + 1; j < M; j++) {
				string next = temp;
                if (i == 0 && next[j] == '0') continue;
				swap(next[i], next[j]);
                if (visited[next + to_string(cnt + 1)]) continue;
                visited[next + to_string(cnt + 1)] = true;
				q.push({ stoi(next), cnt + 1 });
			}
		}
    }
}

int main() {
    FastIO;

    cin >> N >> K;

    string s = to_string(N);
    M = s.size();

    bfs();

    cout << res << "\n";

    return 0;
}