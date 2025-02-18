#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
	int x;
	int cnt;
};

int N, M;
int S, E;
vector<int> arr[10001];
int path[10001];
bool visited[10001];

int bfs(int start, int end) {
	queue<Node> q;
	q.push({start, 0});
	visited[start] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < arr[cur.x].size(); i++) {
			int next = arr[cur.x][i];

			if (!visited[next]) {
				visited[next] = true;
				path[next] = cur.x;
				q.push({ next, cur.cnt + 1 });
			}

			if (next == end) {
				return cur.cnt + 1;
			}
		}
	}
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

	for (int i = 1; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

    cin >> S >> E;

	int res1 = bfs(S, E);

	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}

	int n = path[E];

	while (true) {
		visited[n] = true;
		n = path[n];
		if (n == 0) break;
	}

	int res2 = bfs(E, S);

	cout << res1 + res2 << endl;

	return 0;
}