#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

struct Card {
    int n;

    bool operator<(const Card& c) const {
        return n > c.n;
    }
};

int N;
priority_queue<Card> pq;

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        pq.push({ n });
    }

    int res = 0;

    while (pq.size() > 1) {
        Card a = pq.top();
        pq.pop();

        if (pq.empty()) {
            res += a.n;
            break;
        }

        Card b = pq.top();
        pq.pop();

        res += a.n + b.n;

        if (!pq.empty()) {
            pq.push({ a.n + b.n });
        }
    }

    cout << res << endl;

    return 0;
}
