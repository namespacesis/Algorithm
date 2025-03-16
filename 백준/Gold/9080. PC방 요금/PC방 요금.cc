#include <iostream>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int T;

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int D;
        cin >> D;

        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');

        int start = h * 60 + m;

        int playTime = D;

        int charge = 0;

        while (playTime > 0) {
            if ((start >= 1320 || start <= 180) && playTime >= 300) {
                while (start >= 1320 || start < 480) {
                    if (480 - start <= 60 && 480 - start >= 0) {
                        playTime -= (480 - start);
                        start = 480;
                    }
                    else {
                        start += 60;
                        start %= 1440;
                        playTime -= 60;
                    }
                }
                charge += 5000;
            }
            else {
                start += 60;
                start %= 1440;
                playTime -= 60;
                charge += 1000;
            }
            start %= 1440;
        }

        cout << charge << endl;
    }

    return 0;
}
