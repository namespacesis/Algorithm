#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x;
    vector<int> v;
};

int N, K;
int A, B;
int map[1001][30];
vector<int> arr[1001];
bool visited[1001];

void bfs() {
    queue<Node> q;
    q.push({ A, {A} });
    visited[A] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == B) {
            for (int n : cur.v) {
                cout << n << " ";
            }
            return;
        }

        for (int next : arr[cur.x]) {
            if (visited[next]) continue;

            visited[next] = true;
            vector<int> v = cur.v;
            v.push_back(next);
            q.push({ next, v });
        }
    }

    cout << -1;
    return;
}

int main() {
    FastIO;

    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < K; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 0; k < K; k++) {
				if (map[i][k] != map[j][k]) {
					cnt++;
                    if (cnt > 1) break;
				}
			}
			if (cnt == 1) {
				arr[i].push_back(j);
                arr[j].push_back(i);
			}
		}
	}

    cin >> A >> B;

    bfs();

    return 0;
}
