#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N;
vector<int> arr[1000001];
int dp[1000001][2];
bool visited[1000001];

void find(int x) {
	visited[x] = true;

	dp[x][0] = 1;

	for (int i = 0; i < arr[x].size(); i++) {
		int child = arr[x][i];

		if (visited[child]) continue;

		find(child);

		dp[x][1] += dp[child][0];
		dp[x][0] += min(dp[child][0], dp[child][1]);
	}
}

int main() {
    FastIO;

    cin >> N;

    int u, v;

    for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	find(1);

	int res = min(dp[1][0], dp[1][1]);

	cout << res << "\n";

	return 0;
}
