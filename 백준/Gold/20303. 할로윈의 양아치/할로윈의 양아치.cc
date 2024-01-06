#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;

int parent[30010];
int dp[3010];
int candy[30010], person[30010];

int get_parent(int x) {
	if (x == parent[x])return x;
	return parent[x] = get_parent(parent[x]);
}

void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);

	if (x < y)parent[y] = x;
	else parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> candy[i];
		parent[i] = i;
		person[i] = 1;
	}

	int x, y;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		union_parent(x, y);
	}

	for (int i = 1; i <= n; i++)
		if (parent[i] != i) {
			int p = get_parent(i);
			candy[p] += candy[i];
			person[p] += person[i];
		}

	for (int i = 1; i <= n; i++) {
		if (parent[i] != i) continue;
		for (int j = k - 1; j - person[i] >= 0; j--)
			dp[j] = max(dp[j], dp[j - person[i]] + candy[i]);
	}

	cout << dp[k - 1] << "\n";
	return 0;
}
