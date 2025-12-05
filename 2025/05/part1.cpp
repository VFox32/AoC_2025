#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Range {
    unsigned long long int min;
    unsigned long long int max;
};

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\AoC\\2025\\05\\input.txt");

    int count = 0;

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

    while (std::getline(file, line)) {
        unsigned long long int num = std::stoull(line);

        for(Range range : ranges) {
            if(num >= range.min && num <= range.max) {
                count ++;
                break;
            }
        }
    }

    file.close();

    std::cout << count << std::endl;

    return 0;
}