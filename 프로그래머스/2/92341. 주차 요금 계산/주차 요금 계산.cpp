#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> arr;
    unordered_map<string, int> in;
    unordered_map<string, int> out;
    
    for (int i = 0; i < records.size(); i++) {
        string t = records[i].substr(0, 5);
        string n = records[i].substr(6, 4);
        char type = records[i][11];
        int _time = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
        if (type == 'I') {
            in[n] = _time;
        }
        else {
            out[n] += _time - in[n];
            in.erase(n);
        }
    }
    
    for (auto x : in) {
        int val = 23 * 60 + 59;
        out[x.first] += val - x.second;
    }
    
    for (auto x : out) {
        int val = x.second;
        int res;
        if (val <= fees[0]) {
            res = fees[1];
        }
        else {
            if ((val - fees[0]) % fees[2] == 0) {
                res = fees[1] + ((val - fees[0]) / fees[2]) * fees[3];
            }
            else {
                res = fees[1] + (((val - fees[0]) / fees[2]) + 1) * fees[3];
            }
        }
        arr.push_back({x.first, res});
    }
    
    sort(arr.begin(), arr.end());
    
    for (auto x : arr) {
        answer.push_back(x.second);
    }
    
    return answer;
}