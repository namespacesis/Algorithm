#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int str2int(string str) {
    int m = stoi(str.substr(0, 2));
    int s = stoi(str.substr(3, 2));
    
    int res = (m * 60) + s;
    
    return res;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int t = str2int(pos);
    int video_l = str2int(video_len);
    int op_s = str2int(op_start);
    int op_e = str2int(op_end);
    
    for (int i = 0; i < commands.size(); i++) {
        if (op_s <= t && t <= op_e) {
            t = op_e;
        }
        
        if (commands[i] == "next") {
            t += 10;
            t = min(video_l, t);
        }
        else if (commands[i] == "prev") {
            t -= 10;
            t = max(0, t);
        }
    }
    
    if (op_s <= t && t <= op_e) {
            t = op_e;
    }
    
    string m = to_string(t / 60);
    string s = to_string(t % 60);
    
    if (m.size() == 1) {
        m = "0" + m;
    }
    if (s.size() == 1) {
        s = "0" + s;
    }
    
    answer = m + ":" + s;
    
    return answer;
}