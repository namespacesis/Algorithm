#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N, M, X;
vector<int> better[100001];
vector<int> worse[100001];
bool visited[100001];

int bfs(bool isBetter) {
	queue<int> q;
	q.push(X);
	visited[X] = true;
	int cnt = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : (isBetter ? better[cur] : worse[cur])) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
			cnt++;
		}
	}

	return cnt;
}

int main() {
    FastIO;

	cin >> N >> M >> X;

	int A, B;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		better[B].push_back(A);
		worse[A].push_back(B);
	}

	int U = bfs(true) + 1;
	memset(visited, false, sizeof(visited));
	int V = N - bfs(false);

	cout << U << " " << V << endl;

	return 0;
}
