#include <iostream>
#include <fstream>
#include <sstream>

// https://adventofcode.com/2015/day/2

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2015\\02\\input.txt");

    unsigned long long int area = 0;
    unsigned long long int length = 0;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string side = "";
        int a, b, c;
        while(std::getline(ss, side, 'x')) {
            a = b;
            b = c;
            c = std::stoi(side);
        }

        // sort from least to greatest
        if(c <= a) {
            a = a ^ c;
            c = a ^ c;
            a = a ^ c;
        }
        if(c <= b) {
            b = b ^ c;
            c = b ^ c;
            b = b ^ c;
        }

        // calculate side areas - A1 will be smalles because a-c are sorted
        int A1 = a * b;
        int A2 = b * c;
        int A3 = c * a;

        area += 2*A1 + 2*A2 + 2*A3; // area
        area += A1; // slack
        
        length += 2*a + 2*b; // ribbon
        length += a * b * c; // bow
    }
    file.close();

    std::cout << "part 1: " << area << std::endl;
    std::cout << "part 2: " << length << std::endl;

    return 0;
}