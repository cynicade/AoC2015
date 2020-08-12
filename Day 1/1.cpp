#include <iostream>
#include <string>
#include <vector>
#include "../libraries/readfile.h"

#include <unistd.h>
#include <limits.h>

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

    int floor = 0;

    for (char c : lines[0])
    {
        if (c == '(')
            floor++;
        else
            floor--;
    }

    std::cout << floor << std::endl;

    return 0;
}