#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int match = 0;
    int invisible = 0;
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (lottos[i] == win_nums[j]) {
                match++;
            }
        }
        if (lottos[i] == 0) {
            invisible++;
        }
    }
    
    int res1 = match + invisible;
    int res2 = match;
    7 - res1 < 7 ? res1 = 7 - res1 : res1 = 6;
    7 - res2 < 7 ? res2 = 7 - res2 : res2 = 6;
    answer.push_back(res1);
    answer.push_back(res2);
    return answer;
}