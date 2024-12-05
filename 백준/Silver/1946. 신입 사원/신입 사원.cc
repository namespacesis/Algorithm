#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int T;
int N;
int score1[1000001];
int score2[1000000];


int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            int s1, s2;
            cin >> s1 >> s2;

            score1[s1] = i;
            score2[i] = s2;
        }

        int res = 1;
        int maxV = score2[score1[1]];
        for (int i = 2; i <= N; i++) {
            if (maxV > score2[score1[i]]) {
                res++;
				maxV = score2[score1[i]];
            }
        }

        cout << res << endl;
    }

    return 0;
}
