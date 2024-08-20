#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
int target;

int encode(int sizes[], int dirs[]) {
    int mask = 0;
    for (int i = 0; i < N; i++) {
        mask <<= 4;
        mask |= (sizes[i] << 1) | dirs[i];
    }
    return mask;
}

void decode(int mask, int sizes[], int dirs[]) {
    for (int i = N - 1; i >= 0; i--) {
        dirs[i] = mask & 1;
        mask >>= 1;
        sizes[i] = (mask & 7);
        mask >>= 3;
    }
}

bool is_target(int mask) {
    return mask == target;
}

int rev(int mask, int idx) {
    int sizes[6], dirs[6];
    decode(mask, sizes, dirs);

    reverse(sizes, sizes + idx + 1);
    reverse(dirs, dirs + idx + 1);
    for (int i = 0; i <= idx; i++) {
        dirs[i] ^= 1;
    }

    return encode(sizes, dirs);
}

int bfs(int start) {
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visited.insert(start);

    while (!q.empty()) {
        auto [cur, steps] = q.front();
        q.pop();

        if (is_target(cur)) {
            return steps;
        }

        for (int i = 0; i < N; i++) {
            int next = rev(cur, i);
            if (visited.find(next) != visited.end()) {
                continue;
            }
            visited.insert(next);
            q.push({ next, steps + 1 });
        }
    }
}

int main() {
    FastIO;

    cin >> N;
    int sizes[6], dirs[6];
    for (int i = 0; i < N; i++) {
        int size;
        char dir;
        cin >> size >> dir;
        sizes[i] = size;
        dirs[i] = (dir == '+') ? 0 : 1;
    }

    int target_sizes[6], target_dirs[6] = { 0 };
    for (int i = 0; i < N; i++) {
        target_sizes[i] = i + 1;
    }
    target = encode(target_sizes, target_dirs);

    int start = encode(sizes, dirs);
    int res = bfs(start);

    cout << res << "\n";

    return 0;
}
