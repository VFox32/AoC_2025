#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// https://adventofcode.com/2025/day/7

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2025\\07\\input.txt");

    unsigned long long int *beams;

    std::getline(file, line);
    beams = new unsigned long long int[line.size()];
    // init array with beam start
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == 'S') {
            beams[i] = 1;
        } else {
            beams[i] = 0;
        }
    }

    unsigned long long int count1 = 0;
    while(std::getline(file, line)) { // for every line from top to bottom, since beams only move down
        for(int i = 0; i < line.size(); i++) { // for every position
            if(line[i] == '^' && beams[i] > 0) { // a beam is split
                beams[i - 1] += beams[i]; // amount of paths is current amount + the amount of the split beam
                beams[i + 1] += beams[i]; // ''
                beams[i] = 0; // beam doesnt continue straight after split

                count1++; // count number of splits
            }
        }
    }
    file.close();

    unsigned long long int count2 = 0;
    for(int i = 0; i < line.size(); i++) {
        count2 += beams[i]; // count total number of paths
    }

    std::cout << "part 1: " << count1 << std::endl;
    std::cout << "part 2: " << count2 << std::endl;

    return 0;
}