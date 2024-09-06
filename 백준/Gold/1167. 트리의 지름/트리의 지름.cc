#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;

pair<int, int> dfs(int node, vector<bool>& visited) {
	visited[node] = true;
	int maxDistance = 0;
	int maxNode = node;

	for (const auto&[nextNode, weight] : graph[node]) {
		if (!visited[nextNode]) {
			auto[new_nextNdoe, distance] = dfs(nextNode, visited);
			distance += weight;

			if (distance > maxDistance) {
				maxDistance = distance;
				maxNode = new_nextNdoe;
			}
		}
	}

	return { maxNode, maxDistance };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	graph.resize(N + 1);

	for (int i = 0; i < N; ++i) {
		int P;
		cin >> P;
		
		int C, W;
		while (true) {
			cin >> C;
			if (C == -1) {
				break;
			}
			cin >> W;
			graph[P].push_back({ C, W });
			graph[C].push_back({ P, W });
		}
	}

	vector<bool> visited(N + 1, false);

	auto [tmp_node, tmp] = dfs(1, visited);

	fill(visited.begin(), visited.end(), false);

	auto [tmp2, res] = dfs(tmp_node, visited);

	cout << res << "\n";
	return 0;
}