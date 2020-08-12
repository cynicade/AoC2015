#include <iostream>
#include <string>
#include <vector>
#include "../libraries/readfile.h"
#include "../libraries/contains.h"
#include "../types/coordinates.h"

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

  TCoordinates::Coordinates santa{
      0,
      0};

  int total = 0;

  std::vector<TCoordinates::Coordinates> seen;
  for (char c : lines[0])
  {
    switch (c)
    {
    case '>':
      santa.x++;
      break;
    case 'v':
      santa.y--;
      break;
    case '<':
      santa.x--;
      break;
    default:
      santa.y++;
    }

    if (!libcontains::contains<TCoordinates::Coordinates>(seen, santa))
    {
      seen.push_back(santa);
      total++;
    }
  }

  std::cout << "A total of " << total << "houses received at least one gift from Santa" << std::endl;

  return 0;
}