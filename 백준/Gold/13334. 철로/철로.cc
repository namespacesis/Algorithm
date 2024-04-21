#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, d;
vector <pair<int, int>> people;
priority_queue <int> pq;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int h, o;
		cin >> h >> o;
		if (o < h) { people.push_back({ o,h }); }
		else { people.push_back({ h,o }); }
	}
	cin >> d;

	sort(people.begin(), people.end(), cmp);

	int res = 0;

	for (int i = 0; i < n; i++) {
		int start = people[i].first;
		int end = people[i].second;

		if (end - start > d) continue;
		pq.push(-start);


		while (!pq.empty()) {
			if (-pq.top() + d >= end) {
				break;
			}
			pq.pop();
		}

		res = max(res, (int)pq.size());
	}

	cout << res << "\n";
	return 0;
}