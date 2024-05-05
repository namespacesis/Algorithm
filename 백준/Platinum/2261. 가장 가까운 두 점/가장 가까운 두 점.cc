#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int, int> pi;

int dist(pi a, pi b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

bool compY(pi a, pi b) {
    return a.second < b.second;
}

int closestPair(vector<pi>& points, int left, int right, vector<pi>& temp) {
    if (right - left <= 3) {
        int minDist = INT_MAX;
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j < right; j++) {
                minDist = min(minDist, dist(points[i], points[j]));
            }
        }
        sort(points.begin() + left, points.begin() + right, compY);
        return minDist;
    }

    int mid = (left + right) / 2;
    int mid_x = points[mid].first;

    int d1 = closestPair(points, left, mid, temp);
    int d2 = closestPair(points, mid, right, temp);
    int d = min(d1, d2);

    merge(points.begin() + left, points.begin() + mid, points.begin() + mid, points.begin() + right, temp.begin() + left, compY);
    copy(temp.begin() + left, temp.begin() + right, points.begin() + left);

    vector<pi> strip;
    for (int i = left; i < right; i++) {
        int dx = points[i].first - mid_x;
        if (dx * dx < d) {
            strip.push_back(points[i]);
        }
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) * (strip[j].second - strip[i].second) < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pi> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());
    vector<pi> temp(n);
    int answer = closestPair(points, 0, n, temp);
    cout << answer << "\n";

    return 0;
}
