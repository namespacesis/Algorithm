#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N;
vector<string> words;

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        words.push_back(s);
    }

    sort(words.begin(), words.end());

    vector<string> answer;

    answer.push_back(words[N - 1]);

    for (int i = N - 2; i >= 0; i--) {
        bool flag = false;
        for (int j = 0; j < answer.size(); j++) {
            int cnt = 0;
            for (int k = 0; k < words[i].size(); k++) {
                if (answer[j][k] == words[i][k]) {
                    cnt++;
                }
                else break;
            }
            if (cnt == words[i].size()) {
                flag = true;
            }
        }
        if (!flag) {
            answer.push_back(words[i]);
        }
    }

    cout << answer.size() << "\n";

    return 0;
}
