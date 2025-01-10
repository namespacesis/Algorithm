#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Bale {
    int x, y;

    bool operator<(const Bale &b) const {
		if (x == b.x) return y < b.y;
        return x < b.x;
	}
};

int N;

int main() {
    FastIO;

    cin >> N;

    vector<Bale> bales(N);

    for (int i = 0; i < N; i++) {
		cin >> bales[i].x >> bales[i].y;
	}

    sort(bales.begin(), bales.end());

    vector<int> res;
    res.push_back(bales[0].y);

    for (int i = 1; i < N; i++) {
        if (bales[i].y > res.back()) {
            res.push_back(bales[i].y);
        }
        else {
            auto it = lower_bound(res.begin(), res.end(), bales[i].y);
            *it = bales[i].y;
        }
    }

    int ans = res.size();

    cout << ans << endl;

    return 0;
}