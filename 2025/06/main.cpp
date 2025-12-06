#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// https://adventofcode.com/2025/day/6

struct operation {
    std::vector<unsigned long long int> operands;
    char operator_;
};

unsigned long long int calculate(std::vector<operation> operations) {
    unsigned long long int accu = 0;
    for(operation Operation : operations) {
        if(Operation.operator_ == '+') {
            for(unsigned long long int num : Operation.operands) {
                accu += num;
            }
        } else {
            unsigned long long int tmp = 1;
            for(unsigned long long int num : Operation.operands) {
                tmp *= num;
            }
            accu += tmp;
        }
    }
    return accu;
}

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2025\\06\\input.txt");

    std::vector<std::string> lines;

    while(std::getline(file, line)) {
        if(line == "") break;

        lines.push_back(line);
    }
    file.close();

    // foramt for part 1
    int i = 0;
    std::vector<operation> operations1;
    while(i < lines[0].size()) {
        operation Operation;
        for(int j = 0; j < lines.size() - 1; j++) Operation.operands.push_back(0); // init operand values

        Operation.operator_ = lines[lines.size() - 1][i]; // operator for this operation
        
        bool number = true;
        while(number && i < lines[0].size()) { // while the number(s) are not done
            number = false;
            for(int j = 0; j < lines.size() - 1; j++) { // different number in every row
                if(lines[j][i] != ' ') { // is digid
                    Operation.operands[j] = Operation.operands[j] * 10 + (lines[j][i] - '0'); // append to existing number
                    number = true; // this row was a number - dont start new operation
                }
            }
            i++;
        }
        operations1.push_back(Operation);
    }

    // format for part 2
    i = lines[0].size() - 1;
    std::vector<operation> operations2;
    while(i >= 0) {
        operation Operation;
        bool number = true;
        while(number && i >= 0) { // while the number(s) are not done
            number = false;
            unsigned long long int operand = 0;
            for(int j = 0; j < lines.size() - 1; j++) { // different number in every collumn
                if(lines[j][i] != ' ') { // is digid
                    operand = operand * 10 + (lines[j][i] - '0'); // append to existing number
                    number = true;
                }
            }
            if(number) {
                Operation.operands.push_back(operand);
            } else {
                Operation.operator_ = lines[lines.size() - 1][i + 1]; // operator
            }
            i--;
        }
        operations2.push_back(Operation);
    }
    operations2[operations2.size()-1].operator_ = lines[lines.size() - 1][0]; // last operator cause out of bounds stuff


    unsigned long long int num1 = calculate(operations1);
    unsigned long long int num2 = calculate(operations2);

    std::cout << "part 1: " << num1 << std::endl;
    std::cout << "part 2: " << num2 << std::endl;

    return 0;
}