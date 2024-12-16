#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

struct Card {
    ll n;

    bool operator<(const Card& c) const {
        return n > c.n;
    }
};

int T;
int N;
priority_queue<Card> pq;

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            ll n;
            cin >> n;
            pq.push({ n });
        }

        ll res = 1;

        while (pq.size() > 1) {
            Card a = pq.top();
            pq.pop();

            Card b = pq.top();
            pq.pop();

            res *= (a.n * b.n) % 1000000007;

            pq.push({ a.n * b.n });

            res %= 1000000007;
        }

        pq.pop();

        cout << res << endl;
    }
    
    return 0;
}
