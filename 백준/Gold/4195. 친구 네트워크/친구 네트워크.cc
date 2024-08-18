#include <iostream>
#include <string>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int T;
int F;
int parent[200001];
int cnt[200001];

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) {
		if (cnt[x] < cnt[y]) swap(x, y);
		cnt[x] += cnt[y];
		parent[y] = x;
	}
}

int main() {
	FastIO;

	cin >> T;

	while (T--) {
		cin >> F;

		for (int i = 0; i < 200001; i++) {
			parent[i] = i;
			cnt[i] = 1;
		}

		unordered_map<string, int> um;

		int idx = 1;

		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;

			if (um.find(a) == um.end()) um[a] = idx++;
			if (um.find(b) == um.end()) um[b] = idx++;

			unionParent(um[a], um[b]);

			cout << cnt[findParent(um[a])] << "\n";
		}
	}

	return 0;
}
