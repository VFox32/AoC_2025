#include <iostream>
#include <fstream>

// https://adventofcode.com/2025/day/3

int getMaxPart(std::string line, int start, int end) {
    int index = start;
    // get max earliest max number after start and before end
    for(int i = start; i < line.length() - end; i++) {
        if(line[i] > line[index]) {
            index = i;
        }
    }
    return index;
}

const int numLength = 12; // length of required number for part 2

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\AoC\\2025\\03\\input.txt");

    unsigned long long int num1 = 0;
    unsigned long long int num2 = 0;

    while(std::getline(file, line)) {
        // part 1 - get the two digids and assemble it
        int first = getMaxPart(line, 0, 1);
        int second = getMaxPart(line, first + 1, 0);
        num1 += (line[first] - '0') * 10 + (line[second] - '0');

        // part 2
        int indecies[numLength] = {}; // indecies of the chosen digids

        indecies[0] = getMaxPart(line, 0, numLength - 1); // first chosen manually because no previous one is present
        for(int i = 1; i < numLength; i++) {
            indecies[i] = getMaxPart(line, indecies[i - 1] + 1, numLength - i - 1); // choose next digid based on previous index and remaining number of required didgits
        }

        // assemble number from didgids
        unsigned long long int thisNum = 0;
        for(int i = 0; i < numLength; i++) {
            thisNum = thisNum * 10 + (line[indecies[i]] - '0');
        }
        num2 += thisNum;
    }

    file.close();

    std::cout << "part 1: " << num1 << std::endl;
    std::cout << "part 2: " << num2 << std::endl;

    return 0;
}