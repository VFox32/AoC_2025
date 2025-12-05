#include <iostream>
#include <fstream>

int getMaxPart(std::string line, int start, int end) {
    int index = start;
    for(int i = start; i < line.length() - end; i++) {
        if(line[i] > line[index]) {
            index = i;
        }
    }
    return index;
}

const int numLength = 12;

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\AoC2025\\03\\input.txt");

    unsigned long long int num = 0;

    while(std::getline(file, line)) {
        int indecies[numLength] = {};

        indecies[0] = getMaxPart(line, 0, numLength - 1);
        for(int i = 1; i < numLength; i++) {
            indecies[i] = getMaxPart(line, indecies[i - 1] + 1, numLength - i - 1);
        }

        unsigned long long int thisNum = 0;
        for(int i = 0; i < numLength; i++) {
            thisNum = thisNum * 10 + (line[indecies[i]] - '0');
        }
        num += thisNum;
    }

    file.close();

    std::cout << num << std::endl;

    return 0;
}