#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int A, B, N, M;
bool visited[100001];

int bfs() {
    queue<pair<int, int>> q;
    q.push({ N, 0 });
    visited[N] = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

		if (cur == M) return cnt;

        if (cur + 1 <= 100000 && !visited[cur + 1]) {
			visited[cur + 1] = cnt + 1;
			q.push({ cur + 1, cnt + 1 });
		}

        if (cur - 1 >= 0 && !visited[cur - 1]) {
			visited[cur - 1] = cnt + 1;
			q.push({ cur - 1, cnt + 1 });
		}

        if (cur + A <= 100000 && !visited[cur + A]) {
			visited[cur + A] = cnt + 1;
			q.push({ cur + A, cnt + 1 });
		}

		if (cur - A >= 0 && !visited[cur - A]) {
			visited[cur - A] = cnt + 1;
			q.push({ cur - A, cnt + 1 });
		}

		if (cur + B <= 100000 && !visited[cur + B]) {
			visited[cur + B] = cnt + 1;
			q.push({ cur + B, cnt + 1 });
		}

		if (cur - B >= 0 && !visited[cur - B]) {
			visited[cur - B] = cnt + 1;
			q.push({ cur - B, cnt + 1 });
		}

		if (cur * A <= 100000 && !visited[cur * A]) {
			visited[cur * A] = cnt + 1;
			q.push({ cur * A, cnt + 1 });
		}

		if (cur * B <= 100000 && !visited[cur * B]) {
			visited[cur * B] = cnt + 1;
			q.push({ cur * B, cnt + 1 });
		}
	}
}

int main() {
    FastIO;

    cin >> A >> B >> N >> M;

	int res = bfs();

	cout << res << "\n";

	return 0;
}
