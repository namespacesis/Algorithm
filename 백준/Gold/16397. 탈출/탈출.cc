#include <iostream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int N, T, G;
bool visited[100000];

int bfs() {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt > T) {
			continue;
		}

		if (num == G) {
			return cnt;
		}

		if (num + 1 <= 99999 && !visited[num + 1]) {
			q.push({ num + 1, cnt + 1 });
			visited[num + 1] = true;
		}

		int tmp = num * 2;
		
		if (0 < tmp && tmp <= 99999) {
			string stmp = to_string(tmp);
			tmp -= pow(10, stmp.size() - 1);
			if (!visited[tmp]) {
				q.push({ tmp, cnt + 1 });
				visited[tmp] = true;
			}
		}	
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> T >> G;

	int res = bfs();

	if (res == -1) {
		cout << "ANG" << "\n";
	}
	else {
		cout << res << "\n";
	}

	return 0;
}