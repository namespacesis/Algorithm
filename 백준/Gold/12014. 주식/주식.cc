#include <iostream>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int T;
int N, K;
vector<int> res;

int main() {
    FastIO;

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        res.clear();
        cin >> N >> K;

        int n;
        cin >> n;
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

        if (res.size() < K) {
            cout << "Case #" << tc << "\n";
            cout << "0\n";
        }
        else {
            cout << "Case #" << tc << "\n";
            cout << "1\n";
        }
    }

    return 0;
}
