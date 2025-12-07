#include <iostream>
#include <fstream>

// https://adventofcode.com/2015/day/3

struct position {
    int x, y;
    bool a;
    bool operator==(const position& other) const {
        return x == other.x && y == other.y;
    }
};
struct hash {
    std::size_t operator()(const position& p) const {
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

struct set {
    position* positions;
    int size;

    set(int s) {
        positions = new position[s];
        size = s;

        for(int i = 0; i < size; i++) {
            positions[i] = position{0, 0, false};
        }
    }

    void insert(position p) {
        for(int i = 0; i < size; i++) {
            if(!positions[i].a) {
                positions[i] = p;
                return;
            }
            if(positions[i].x == p.x && positions[i].y == p.y) return;
        }
    }

    int length() {
        for(int i = 0; i < size; i++) {
            if(!positions[i].a) return i;
        }
        return 0;
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

    set positions1(line.length());
    set positions2(line.length());

    position p1 = position{0, 0, true};
    position p2 = position{0, 0, true}, p3 = position{0, 0, true};

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

    std::cout << "part 1: " << positions1.length() << std::endl;
    std::cout << "part 2: " << positions2.length() << std::endl;

    return 0;
}