#include <iostream>
#include <string>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N, K;
int M;
int res = -1;
bool visited[1000001][11];

void bfs() {
    queue<pair<int, int>> q;
    string s = to_string(N);
    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            string temp = s;
            if (i == 0 && temp[j] == '0') continue;
            swap(temp[i], temp[j]);
            if (visited[stoi(temp)][1]) continue;
            visited[stoi(temp)][1] = true;
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
				if (!visited[stoi(next)][cnt + 1]) {
					visited[stoi(next)][cnt + 1] = true;
					q.push({ stoi(next), cnt + 1 });
				}
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