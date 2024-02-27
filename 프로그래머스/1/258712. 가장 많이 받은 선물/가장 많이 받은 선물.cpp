#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> giftIndex;
    unordered_map<string, unordered_map<string, int>> giftRecord;

    for (const auto& gift : gifts) {
        size_t pos = gift.find(" ");
        string giver = gift.substr(0, pos);
        string receiver = gift.substr(pos + 1);

        giftRecord[giver][receiver]++;
        giftIndex[giver]++;
        giftIndex[receiver]--;
    }

    unordered_map<string, int> nextMonthGifts;
    for (const auto& f : friends) {
        for (const auto& fr : friends) {
            if (f != fr) {
                int giverGifts = giftRecord[f][fr];
                int receiverGifts = giftRecord[fr][f];

                if (giverGifts > receiverGifts) {
                    nextMonthGifts[f]++;
                } else if (giverGifts < receiverGifts) {
                    nextMonthGifts[fr]++;
                } else {
                    if (giftIndex[f] > giftIndex[fr]) {
                        nextMonthGifts[f]++;
                    } else if (giftIndex[f] < giftIndex[fr]) {
                        nextMonthGifts[fr]++;
                    }
                }
            }
        }
    }

    int maxGifts = 0;
    for (const auto& nmg : nextMonthGifts) {
        if (nmg.second > maxGifts) {
            maxGifts = nmg.second;
        }
    }

    return maxGifts / 2;
}
