#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// https://adventofcode.com/2025/day/5

struct Range {
    unsigned long long int min;
    unsigned long long int max;
};

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2025\\05\\input.txt");

    unsigned long long int count1 = 0;
    unsigned long long int count2 = 0;

    std::vector<Range> ranges;

    while(std::getline(file, line)) {
        if(line == "") break;

        std::stringstream range(line);

        std::string min;
        std::string max;

        std::getline(range, min, '-');
        std::getline(range, max, '-');

        ranges.push_back(Range{std::stoull(min), std::stoull(max)}); // accumulate all ranges
    }

    // part 1
    while (std::getline(file, line)) {
        unsigned long long int num = std::stoull(line);

        for(Range range : ranges) {
            if(num >= range.min && num <= range.max) { // if number is within any range, increment count
                count1 ++;
                break;
            }
        }
    }

    file.close();

    // part 2
    std::sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) { 
        if (a.min != b.min) return a.min < b.min; // sort by min value first if possible
        return a.max < b.max; // sort by max value if not
    });

    std::vector<Range> result; // vector of new ranges without overlap
    Range current = ranges[0];
    for (unsigned long long int i = 1; i < ranges.size(); ++i) {
        const Range &next = ranges[i];

        if (next.min <= current.max) { // if it overlaps, combine ranges, if not, add the current one
            current.max = std::max(current.max, next.max); // expand current range to include next one
        } else {
            result.push_back(current); // add current range if it cant be expanded
            current = next;
        }
    }
    result.push_back(current); // add last remaining range

    for(int i = 0; i < result.size(); i++) {
        Range range = result[i];
        count2 += range.max - range.min + 1; // accumulate size of all ranges
    }

    std::cout << "part 1: " << count1 << std::endl;
    std::cout << "part 2: " << count2 << std::endl;

    return 0;
}