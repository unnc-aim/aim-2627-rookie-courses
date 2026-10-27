#include <algorithm>
#include <iostream>
#include <vector>

struct Record {
    int id = 0;
    int score = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<Record> records(n);
    for (Record & r : records)
        std::cin >> r.id >> r.score;
    std::sort(records.begin(), records.end(), [](const Record &a, const Record &b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.id < b.id;
    });
    for (const Record & r : records)
        std::cout << r.id << '\n';
    return 0;
}
