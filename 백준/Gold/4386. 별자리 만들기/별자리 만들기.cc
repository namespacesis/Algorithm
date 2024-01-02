#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int parent[101];
vector<pair<double, double>> arr;
vector<pair<double, pair<double, double>>> graph;
double res = 0;

int getParent(int x) {
	if (parent[x] == x) return x;
	else {
		parent[x] = getParent(parent[x]);
		return parent[x];
	}
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		arr.push_back({ x, y });
	}

	int s = arr.size();

	for (int i = 0; i < s; i++) {
		double x1 = arr[i].first;
		double y1 = arr[i].second;

		for (int j = i + 1; j < s; j++) {
			double x2 = arr[j].first;
			double y2 = arr[j].second;

			double dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
			graph.push_back({ dist, {i + 1, j + 1} });
		}
	}

	sort(graph.begin(), graph.end());

	for (int i = 1; i <= n; i++) parent[i] = i;

	s = graph.size();

	for (int i = 0; i < s; i++) {
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		double c = graph[i].first;

		if (getParent(a) == getParent(b)) continue;

		unionParent(a, b);
		res += c;
	}

	cout << res << "\n";
	return 0;
}