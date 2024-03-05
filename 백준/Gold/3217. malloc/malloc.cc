#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

struct Node {
    int start;
    int end;
};

uint32_t id(std::string_view sv) {
    return sv[0] | (sv[1] << 8) | (sv[2] << 16) | (sv[3] << 24);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::list<Node> memory;
    std::unordered_map<uint32_t, std::list<Node>::iterator> table;

    memory.push_back({ 1, 1 });
    memory.push_back({ 100'001, 100'001 });

    while (n--) {
        std::string command;
        std::cin >> command;

        if (command[0] == 'f') { // "free" command
            auto var = id(std::string_view(command).substr(5, 4));

            auto it = table.find(var);
            if (it != table.end()) {
                memory.erase(it->second);
                table.erase(it);
            }
        }
        else if (command[0] == 'p') { // "print" command
            auto var = id(std::string_view(command).substr(6, 4));

            auto it = table.find(var);
            if (it != table.end()) {
                std::cout << it->second->start << '\n';
            }
            else {
                std::cout << "0\n";
            }
        }
        else { // "malloc" command
            auto var = id(std::string_view(command).substr(0, 4));
            int size = std::stoi(command.substr(12));

            auto it = table.find(var);
            if (it != table.end()) {
                table.erase(it);
            }

            for (auto it = memory.begin(); std::next(it) != memory.end(); ++it) {
                if (size <= std::next(it)->start - it->end) {
                    auto inserted = memory.insert(std::next(it), { it->end, it->end + size });
                    table[var] = inserted;
                    break;
                }
            }
        }
    }

    return 0;
}
