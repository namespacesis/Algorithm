#include <string>
#include <vector>
#include <tuple>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    int max_h = health;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];

    int S = 0;
    int E = attacks[attacks.size() - 1][0];

    int cnt = 0;
    int target = 0;

    while (S < E) {
        S++;

        int at = attacks[target][0];
        int d = attacks[target][1];

        if (at == S) {
            target++;
            health -= d;
            cnt = 0;
            if (health <= 0) {
                answer = -1;
                break;
            }
        }
        
        else {
            cnt++;
            health += x;
            if (cnt == t) {
                health += y;
                cnt = 0;
            }
            if (health > max_h) {
                health = max_h;
            }
        }
        answer = health;
    }

    return answer;
}