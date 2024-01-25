#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<int> augment;
    vector<int> sequence;
    vector<int> DP(N);
    for (int i = 0; i < N; i++) {
        DP[i] = 1;
        int temp;
        cin >> temp;
        augment.push_back(temp);
        if (sequence.size() == 0 or sequence.back() < temp) {
            sequence.push_back(temp);
            DP[i] = sequence.size();
        }
        else {
            *lower_bound(sequence.begin(), sequence.end(), temp) = temp;
            DP[i] = lower_bound(sequence.begin(), sequence.end(), temp) - sequence.begin() + 1;
        }
    }
    cout << sequence.size() << "\n";

    int cnt = sequence.size();

    vector<int> answer;

    for (int i = N - 1; i >= 0; i--) {
        if (cnt == 0) {
            break;
        }
        if (DP[i] == cnt) {
            answer.push_back(augment[i]);
            cnt--;
        }
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i] << " ";
    }

    cout << "\n";
    return 0;
}
