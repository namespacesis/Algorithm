#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct Point {
    long long x, y;

    bool operator <(const Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};


long long ccw(const Point& p0, const Point& p1, const Point& p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

vector<Point> convexHull(vector<Point>& points) {
    if (points.size() <= 1) return points;
    sort(points.begin(), points.end());
    vector<Point> hull;

    for (int i = 0; i < points.size(); ++i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int t = hull.size() + 1;

    for (int i = points.size() - 1; i >= 0; --i) {
        while (hull.size() >= t && ccw(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();
    return hull;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    vector<Point> result = convexHull(points);
    cout << result.size() << "\n";
    return 0;
}
