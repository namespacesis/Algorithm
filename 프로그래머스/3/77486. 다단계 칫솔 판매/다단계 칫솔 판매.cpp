#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;
unordered_map<string, int> profit;
string parent[10000];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    int idx = 0;
    
    for (int i = 0; i < enroll.size(); i++) {
        um[enroll[i]] = idx;
        idx++;
    }
    
    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] != "-") {
            parent[um[enroll[i]]] = referral[i];
        }
    }
    
    for (int i = 0; i < seller.size(); i++) {
        string s = seller[i];
        int money = amount[i] * 100;
        while (true) {
            if (money == 0) break;
            profit[s] += (money / 10) * 9 + (money % 10);
            if (s == parent[um[s]]) {
                break;
            }
            s = parent[um[s]];
            money = (money / 10);
        }
    }
    
    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(profit[enroll[i]]);
    }
    
    return answer;
}