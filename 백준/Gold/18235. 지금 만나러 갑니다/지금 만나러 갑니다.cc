#include <iostream>
#include <queue>
#include <cmath>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

struct Duck {
    int x;
    int cnt;
};

int N, A, B;
int visited[500001];

int main() {
    FastIO;

    cin >> N >> A >> B;

    queue<Duck> q;
    q.push({ A, 0 });
    q.push({ B, 0 });

    while (!q.empty()) {
        Duck cur = q.front();
        q.pop();

        int x = cur.x;
        int cnt = cur.cnt;

        for (int i = 0; i < 2; i++) {
            int nx;
            if (i == 0) {
                nx = x + pow(2, cnt);
            }
            else {
                nx = x - pow(2, cnt);
            }

            if (nx < 1 || nx > N) continue;

            if (visited[nx] == cnt + 1) {
                cout << cnt + 1 << endl;
                return 0;
            }

            visited[nx] = cnt + 1;
            q.push({ nx, cnt + 1 });
        }
    }

    cout << -1 << endl;

    return 0;
}
