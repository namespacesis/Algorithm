#include <iostream>
#include <vector>

using namespace std;

const int MAX_STATIONS = 1000001;

struct Node {
    int prev, next;
} stations[MAX_STATIONS];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> input(N);
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    for (int i = 0; i < N; ++i) {
        int current = input[i];
        int next = input[(i + 1) % N];
        int prev = input[(i - 1 + N) % N];
        stations[current].next = next;
        stations[current].prev = prev;
    }

    while (M--) {
        string command;
        cin >> command;
        int a, b;

        if (command == "BN" || command == "BP") {
            cin >> a >> b;
            int next = (command == "BN") ? stations[a].next : a;
            int prev = (command == "BN") ? a : stations[a].prev;

            cout << (command == "BN" ? stations[a].next : stations[a].prev) << "\n";

            stations[b].next = next;
            stations[b].prev = prev;
            stations[next].prev = b;
            stations[prev].next = b;
        }
        else {
            cin >> a;
            int target = (command == "CN") ? stations[a].next : stations[a].prev;

            cout << target << "\n";

            stations[stations[target].prev].next = stations[target].next;
            stations[stations[target].next].prev = stations[target].prev;
        }
    }

    return 0;
}
