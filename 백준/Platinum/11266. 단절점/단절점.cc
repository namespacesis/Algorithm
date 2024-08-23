#include <iostream>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int V, E;
int cnt = 1;
vector<int> graph[10001];
int visited[10001];
bool cutEdge[10001];
vector<int> res;

int dfs(int node, bool isRoot) {
	visited[node] = cnt++;
	int ret = visited[node];
	int child = 0;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];

		if (!visited[next]) {
			child++;
			int prev = dfs(next, false);
			if (!isRoot && prev >= visited[node]) {
				cutEdge[node] = true;
			}
			ret = min(ret, prev);
		} else {
			ret = min(ret, visited[next]);
		}
	}

	if (isRoot && child > 1) {
		cutEdge[node] = true;
	}

	return ret;
}

int main() {
    FastIO;

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            dfs(i, true);
        }
    }

	for (int i = 1; i <= V; i++) {
		if (cutEdge[i]) {
			res.push_back(i);
		}
	}

	cout << res.size() << "\n";

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}
