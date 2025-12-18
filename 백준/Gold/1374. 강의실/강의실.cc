#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Room {
    int id;
    int s;
    int e;

    bool operator<(const Room& r) const {
        if (s == r.s) return e < r.e;
        return s < r.s;
    }
};

int N;
vector<Room> lectures;
priority_queue<int, vector<int>, greater<int>> end_times;

int main() {
    FastIO;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int idx, st, et;
        cin >> idx >> st >> et;
        lectures.push_back({idx, st, et});
    }

    sort(lectures.begin(), lectures.end());

    for (int i = 0; i < N; ++i) {
        if (!end_times.empty() && end_times.top() <= lectures[i].s) {
            end_times.pop();
        }
        
        end_times.push(lectures[i].e);
    }

    cout << end_times.size() << endl;

    return 0;
}