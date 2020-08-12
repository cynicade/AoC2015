#include <vector>
#include <string>
#include "split.h"

bool isEscaped(char c) {
    return c == '\n' || c == '\t' || c == '\r' || c =='\v';
}

std::vector<std::string> libsplit::split(std::string toSplit, char delimiter) {
    std::vector<std::string> returnValue;
    std::string temp; // holds temporary value until it is pushed to the vector

    for (char c : toSplit) {
        if (c != delimiter && !isEscaped(c)) {
            temp.push_back(c);
        }
        else {
            returnValue.push_back(temp);
            temp = "";
        }
    }

    returnValue.push_back(temp);

    return returnValue;
}
