#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (int i = 0; i < number.size(); i++) {
        while (answer.size() != 0 && answer.back() < number[i] && k > 0) {
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }
    
    while (k--) {
        answer.pop_back();
    }

    return answer;
}
