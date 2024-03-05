#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    int start;
    int end;
};

uint32_t id(string_view sv) {
    return sv[0] | (sv[1] << 8) | (sv[2] << 16) | (sv[3] << 24);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    list<Node> memory;
    unordered_map<uint32_t, list<Node>::iterator> table;

    memory.push_back({ 1, 1 });
    memory.push_back({ 100001, 100001 });

    while (n--) {
        string command;
        cin >> command;

        if (command[0] == 'f') { // "free" command
            auto var = id(string_view(command).substr(5, 4));

            auto it = table.find(var);
            if (it != table.end()) {
                memory.erase(it->second);
                table.erase(it);
            }
        }
        else if (command[0] == 'p') { // "print" command
            auto var = id(string_view(command).substr(6, 4));

            auto it = table.find(var);
            if (it != table.end()) {
                cout << it->second->start << '\n';
            }
            else {
                cout << "0\n";
            }
        }
        else { // "malloc" command
            auto var = id(string_view(command).substr(0, 4));
            int size = stoi(command.substr(12));

            auto it = table.find(var);
            if (it != table.end()) {
                table.erase(it);
            }

            for (auto it = memory.begin(); next(it) != memory.end(); ++it) {
                if (size <= next(it)->start - it->end) {
                    auto inserted = memory.insert(next(it), { it->end, it->end + size });
                    table[var] = inserted;
                    break;
                }
            }
        }
    }

    return 0;
}
