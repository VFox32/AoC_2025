#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// https://adventofcode.com/2025/day/7

struct box {
    long long int x, y, z;
};

struct connection {
    int a, b;
    long long int len;
};

struct graph {
    std::vector<std::vector<int>> networks;

    int findBox(int i) { // get network index from box index
        for(int j = 0; j < networks.size(); j++) {
            for(int k : networks[j]) {
                if(k == i) {
                    return j;
                }
            }
        }
        return -1;
    }

    void addConnection(connection c) {
        int i1 = findBox(c.a);
        int i2 = findBox(c.b);

        if(i1 >= 0 && i2 >= 0) { // if both are present, combine their networks
            if(i1 == i2) return;

            std::vector<int> c = networks[i1];
            c.insert(c.end(), networks[i2].begin(), networks[i2].end());

            std::sort(c.begin(), c.end());
            c.erase(std::unique(c.begin(), c.end()), c.end());

            networks[i1] = c;
            networks.erase(networks.begin() + i2);
        }
        else if(i1 >= 0 && i2 <  0) networks[i1].push_back(c.b); // if one is present, add the other
        else if(i1 <  0 && i2 >= 0) networks[i2].push_back(c.a); // ''
        else { // if none are present, add both to a new network
            networks.push_back(std::vector<int>());
            networks[networks.size() - 1].push_back(c.a);
            networks[networks.size() - 1].push_back(c.b);
        }
    }
};

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2025\\08\\input.txt");

    std::vector<box> boxes;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string coord;
        box Box = box();
        while (std::getline(ss, coord, ',')) {
            Box.x = Box.y;
            Box.y = Box.z;
            Box.z = std::stoul(coord);
        }
        boxes.push_back(Box);
    }

    std::vector<connection> connections;
    for(int i = 0; i < boxes.size() - 1; i++) {
        for(int j = i + 1; j < boxes.size(); j++) { // all unique connections
            long long int x = boxes[j].x - boxes[i].x;
            long long int y = boxes[j].y - boxes[i].y;
            long long int z = boxes[j].z - boxes[i].z;

            long long int l = x*x + y*y + z*z; // distance between boxes

            connections.push_back(connection{i, j, l});
        }
    }

    // sort from smalles distance to largest
    sort(connections.begin(), connections.end(),
        [](const connection& a, const connection& b) {
        return a.len < b.len;
    });

    graph Graph;
    for(int i = 0; i < 1000; i++) {
        Graph.addConnection(connections[i]); // make first 1k smallest connections
    }

    sort(Graph.networks.begin(), Graph.networks.end(), // sort from largest network to smallest
        [](const std::vector<int>& a, const std::vector<int>& b) {
        return a.size() > b.size();
    });

    int part1 = Graph.networks[0].size() * Graph.networks[1].size() * Graph.networks[2].size(); // part 1

    long long int part2;
    for(int i = 1000; i < connections.size(); i++) { // do remaining connections
        Graph.addConnection(connections[i]);
        if(Graph.networks[0].size() == boxes.size()) { // if all in one network
            part2 = boxes[connections[i].a].x * boxes[connections[i].b].x; // part 2
            break;
        }
    }
    
    std::cout << "part 1: " << part1 << std::endl;
    std::cout << "part 2: " << part2 << std::endl;

    return 0;
}