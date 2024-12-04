#include <iostream>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

vector<int> res;

int main() {
    FastIO;

    int N, n;

    while (cin >> N >> n) {
        res.clear();
        res.push_back(n);

        for (int i = 1; i < N; i++) {
            cin >> n;
            if (n > res.back()) {
                res.push_back(n);
            }
            else {
                *lower_bound(res.begin(), res.end(), n) = n;
            }
        }

        cout << res.size() << "\n";
    }

    return 0;
}
