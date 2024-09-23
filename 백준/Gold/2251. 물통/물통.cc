#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

struct Bucket {
    int a, b, c;
};

int A, B, C;
bool visited[201][201][201];
vector<int> ans;

int main() {
    FastIO;

    cin >> A >> B >> C;

    queue<Bucket> q;
    q.push({ 0, 0, C });

    while (!q.empty()) {
        Bucket cur = q.front();
        q.pop();

		if (!visited[cur.a][cur.b][cur.c]) {
			visited[cur.a][cur.b][cur.c] = true;

			if (cur.a == 0) ans.push_back(cur.c);

			if (cur.a + cur.b > B) q.push({ cur.a + cur.b - B, B, cur.c });
			else q.push({ 0, cur.a + cur.b, cur.c });

			if (cur.a + cur.c > C) q.push({ cur.a + cur.c - C, cur.b, C });
			else q.push({ 0, cur.b, cur.a + cur.c });

			if (cur.b + cur.a > A) q.push({ A, cur.b + cur.a - A, cur.c });
			else q.push({ cur.b + cur.a, 0, cur.c });

			if (cur.b + cur.c > C) q.push({ cur.a, cur.b + cur.c - C, C });
			else q.push({ cur.a, 0, cur.b + cur.c });

			if (cur.c + cur.a > A) q.push({ A, cur.b, cur.c + cur.a - A });
			else q.push({ cur.c + cur.a, cur.b, 0 });

			if (cur.c + cur.b > B) q.push({ cur.a, B, cur.c + cur.b - B });
			else q.push({ cur.a, cur.c + cur.b, 0 });
		}
    }

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}
