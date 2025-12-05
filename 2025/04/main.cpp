#include <iostream>
#include <fstream>
#include <vector>

// https://adventofcode.com/2025/day/4

int removeRolls(std::vector<std::string> &grid) {
    int count = 0;

    // iterate over grid
    for(int y = 0; y < grid.size(); y++) {
        for(int x = 0; x < grid[0].length(); x++) {
            if(grid[y][x] != '@') continue;

            // iterate over the surrounding 8 tiles (+1 for current tile)
            int amount = 0;
            for(int Y = -1; Y <= 1; Y++) {
                if(y+Y < 0 || y+Y >= grid.size()) continue;
                for(int X = -1; X <= 1; X++) {
                    if(x+X < 0 || x+X >= grid.size()) continue;

                    if(grid[y+Y][x+X] == '.') continue;
                    amount++; // count towards count of surrounded cells
                }
            }

        if(amount <= 4) { // <= 4 because current cell is included
                grid[y][x] = 'x'; // mark cell for removal
                count ++;
            }
        }
    }
    for(int y = 0; y < grid.size(); y++) {
        for(int x = 0; x < grid[0].length(); x++) {
            if(grid[y][x] == 'x') grid[y][x] = '.'; // actually remove cells
        }
    }

    return count;
}

#include <filesystem>

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2025\\04\\input.txt");

    std::cout << "CWD: " << std::filesystem::current_path() << std::endl;

    int count1 = 0;
    int count2 = 0;

    std::vector<std::string> grid;

    while(std::getline(file, line)) {
        grid.push_back(line);
    }

    bool first = true; // is first removal?
    bool moved = true;
    while(moved){
        moved = false;
        
        int count = removeRolls(grid); // amount of rolls removed this time

        if(first) {
            count1 = count; // only count first iteration for part 1
            first = false;
        }

        count2 += count;

        if(count > 0) moved = true; // as long as something was removed, there might be new ones available
    }

    file.close();

    std::cout << "part 1: " << count1 << std::endl;
    std::cout << "part 2: " << count2 << std::endl;

    return 0;
}