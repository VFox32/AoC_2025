#include <iostream>
#include <fstream>
#include <unordered_set>

// https://adventofcode.com/2015/day/3

struct position {
    int x, y;
    bool operator==(const position& other) const {
        return x == other.x && y == other.y;
    }
};
struct hash {
    std::size_t operator()(const position& p) const {
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

void move(position &p, char dir) {
    if(dir == '^') p.y++;
    else if(dir == 'v') p.y--;
    else if(dir == '>') p.x++;
    else p.x--;
}

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2015\\03\\input.txt");

    std::getline(file, line);
    file.close();

    std::unordered_set<position, hash> positions1;
    std::unordered_set<position, hash> positions2;

    position p1 = position{0, 0};
    position p2 = position{0, 0}, p3 = position{0, 0};

    positions1.insert(p1);
    positions2.insert(p2);

    for(int i = 0; i < line.length(); i++) {
        move(p1, line[i]);
        positions1.insert(p1);

        if(i % 2 == 0) move(p2, line[i]);
        else move(p3, line[i]);
        positions2.insert(p2);
        positions2.insert(p3);
    }

    std::cout << "part 1: " << positions1.size() << std::endl;
    std::cout << "part 2: " << positions2.size() << std::endl;

    return 0;
}