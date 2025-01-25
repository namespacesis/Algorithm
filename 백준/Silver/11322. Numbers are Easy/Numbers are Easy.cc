#include <iostream>
#include <queue>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int T;
int N;
bool visited[301];

string bfs() {
    if (N == 1) return "1";

    queue<pair<string, int>> q;
    q.push({"1", 1 % N});
    visited[1 % N] = true;

    while (!q.empty()) {
        string num = q.front().first;
        int remainder = q.front().second;
        q.pop();

        if (remainder == 0) return num;

        int rem0 = (remainder * 10) % N;
        if (!visited[rem0]) {
            q.push({ num + "0", rem0 });
            visited[rem0] = true;
        }

        int rem1 = (remainder * 10 + 1) % N;
        if (!visited[rem1]) {
            q.push({ num + "1", rem1 });
            visited[rem1] = true;
        }
	}
}

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> N;
        fill(visited, visited + 301, false);
        string res = bfs();
		cout << res << endl;
    }

	return 0;
}