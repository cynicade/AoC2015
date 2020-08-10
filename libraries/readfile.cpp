#include "readfile.h"
#include <iostream>
#include <fstream>
#include <vector>

namespace libreader
{
  ReadFile::ReadFile(std::string fileName)
  {
    this->fileName = fileName;
  }

  void ReadFile::read()
  {
    std::string line;
    std::ifstream file(fileName);

    if (file.is_open())
    {
      while (getline(file, line))
      {
        ReadFile::lineCount++;
        ReadFile::lines.push_back(line);
      }

      file.close();
    }
    else
    {
      std::cout << "ERROR: Unable to open " << fileName << std::endl;
    }
  }

  int ReadFile::getLineCount()
  {
    return ReadFile::lineCount;
  }

  std::vector<std::string> ReadFile::getLines()
  {
    return ReadFile::lines;
  }

  ReadFile::~ReadFile()
  {
  }
} // namespace libreader