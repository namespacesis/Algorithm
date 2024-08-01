#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
vector<char> arr;

pair<int, int> calculateScore(const vector<char>& cards, int n) {
    int junsuk_score = 0;
    int suhyun_score = 0;

    for (int i = 0; i < 2 * n; i += 2) {
        if (cards[i] != cards[i + 1]) {
            if (cards[i] == 'O') {
                junsuk_score++;
            }
            else {
                suhyun_score++;
            }
        }
    }

    return { junsuk_score, suhyun_score };
}

bool canJunsukWin(const vector<char>& cards, int n) {
    auto score = calculateScore(cards, n);
    return score.first > score.second;
}

int bfs(int n, vector<char>& cards) {
    if (canJunsukWin(cards, n)) {
        return 0;
    }

    queue<pair<vector<char>, int>> q;
    unordered_set<string> visited;

    q.push({ cards, 0 });
    visited.insert(string(cards.begin(), cards.end()));

    while (!q.empty()) {
        auto [current_cards, depth] = q.front();
        q.pop();

        for (int i = 1; i < 2 * n; ++i) {
            vector<char> modified_cards = current_cards;
            modified_cards.erase(modified_cards.begin() + i);
            modified_cards.insert(modified_cards.begin(), current_cards[i]);

            if (canJunsukWin(modified_cards, n)) {
                return depth + 1;
            }

            string card_state(modified_cards.begin(), modified_cards.end());
            if (visited.find(card_state) == visited.end()) {
                q.push({ modified_cards, depth + 1 });
                visited.insert(card_state);
            }
        }
    }

    return -1;
}

int main() {
    FastIO;

    cin >> N;

    arr.resize(N * 2);

    for (int i = 0; i < N * 2; i++) {
        cin >> arr[i];
    }

    cout << bfs(N, arr) << "\n";

    return 0;
}
