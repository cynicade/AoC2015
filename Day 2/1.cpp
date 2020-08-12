#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../libraries/readfile.h"
#include "../libraries/split.h"

struct Dimensions
{
    int length;
    int width;
    int height;
};

Dimensions parseLine(std::string line);

int main(int argc, char **argv)
{
    std::string fileName;

    if (argc == 2)
    {
        fileName = argv[1];
    }
    else
    {
        fileName = "input.txt";
    }

    libreadfile::ReadFile file = libreadfile::ReadFile(fileName);
    file.read();
    std::vector<std::string> lines = file.getLines();
    std::vector<Dimensions> boxes;

    for (std::string line : lines) {
        boxes.push_back(parseLine(line));
    }

    int total = 0;

    for (Dimensions box : boxes) {
        total += 2*box.height*box.length + 2*box.length*box.width +
            2*box.height*box.width + (box.height*box.width*box.length / (std::max({ box.height, box.width, box.length })));
    }

    std::cout << "The total is " << total << std::endl;

    return 0;
}

Dimensions parseLine(std::string line)
{
    Dimensions returnValue;
    std::vector<std::string> temp = libsplit::split(line, 'x');
    returnValue.length = std::stoi(temp[0]);
    returnValue.width = std::stoi(temp[1]);
    returnValue.height = std::stoi(temp[2]);

    return returnValue;
}