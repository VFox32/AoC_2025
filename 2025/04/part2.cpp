#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\AoC2025\\04\\input.txt");

    int count = 0;

    std::vector<std::string> grid;

    while(std::getline(file, line)) {
        grid.push_back(line);
    }

    bool moved = true;
    while(moved){
        moved = false;
        for(int y = 0; y < grid.size(); y++) {
            for(int x = 0; x < grid[0].length(); x++) {
                if(grid[y][x] != '@') continue;

                int amount = 0;
                for(int Y = -1; Y <= 1; Y++) {
                    if(y+Y < 0 || y+Y >= grid.size()) continue;
                    for(int X = -1; X <= 1; X++) {
                        if(x+X < 0 || x+X >= grid.size()) continue;

                        if(grid[y+Y][x+X] == '.') continue;
                        amount++;
                    }
                }

                if(amount <= 4) {
                    grid[y][x] = 'x';
                    moved = true;
                    count ++;
                }
            }
        }
        for(int y = 0; y < grid.size(); y++) {
            for(int x = 0; x < grid[0].length(); x++) {
                if(grid[y][x] == 'x') grid[y][x] = '.';
            }
        }
    }

    file.close();

    std::cout << count << std::endl;

    return 0;
}