#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N, K;
string s;
int check[3001];

int bfs(int back) {
    queue<pair<int, int>> q;
    check[back] = 1;
    q.push({ back, 0 });
    while (!q.empty()) {
        int back_coin = q.front().first;
        int x = q.front().second;
        q.pop();
        if (back_coin == N) return x;
        int front_coin = N - back_coin;
        for (int i = 0; i <= K; i++) {
            int reverse_back = i;
            int reverse_front = K - i;
            if (reverse_back > back_coin || reverse_front > front_coin) continue;
            int next_back = back_coin - reverse_back + reverse_front;
            if (!check[next_back]) {
                check[next_back] = 1;
                q.push({ next_back, x + 1 });
            }
        }
    }
    return -1;
}

void solve() {
    int back = 0;
    for (char c : s) if (c == 'T') back++;
    memset(check, 0, sizeof(check));
    int ans = bfs(back);
    cout << ans << endl;
}

int main() {
    FastIO;

	cin >> N >> K;

    cin >> s;

    solve();

    return 0;
}
