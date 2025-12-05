#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Range {
    unsigned long long int min;
    unsigned long long int max;
};

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\AoC\\2025\\05\\input.txt");

    std::vector<Range> ranges;

    while(std::getline(file, line)) {
        if(line == "") break;

        std::stringstream range(line);

        std::string min;
        std::string max;

        std::getline(range, min, '-');
        std::getline(range, max, '-');

        ranges.push_back(Range{std::stoull(min), std::stoull(max)});
    }

    file.close();

    std::sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) {
        if (a.min != b.min) return a.min < b.min;
        return a.max < b.max;
    });

    std::vector<Range> result;
    Range current = ranges[0];
    for (unsigned long long int i = 1; i < ranges.size(); ++i) {
        const Range &next = ranges[i];

        bool overlaps;
        overlaps = (next.min <= current.max);

        if (overlaps) {
            current.max = std::max(current.max, next.max);
        } else {
            result.push_back(current);
            current = next;
        }
    }
    result.push_back(current);

    unsigned long long int count = 0;
    for(int i = 0; i < result.size(); i++) {
        Range range = result[i];
        count += range.max - range.min + 1;
    }

    std::cout << count << std::endl;

    return 0;
}