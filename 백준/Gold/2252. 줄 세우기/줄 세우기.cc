#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A, B;
vector<int> arr[32001];
bool visited[32001] = { false };

void dfs(int node) {
	visited[node] = true;

	for (int i = 0; i < arr[node].size(); i++) {
		if (!visited[arr[node][i]]) {
			dfs(arr[node][i]);
		}
	}

	cout << node << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		arr[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	cout << "\n";
	return 0;
}