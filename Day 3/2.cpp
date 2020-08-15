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

  TCoordinates::Coordinates robot{
      0,
      0};

  int total = 0;
  bool santasTurn = true;

  std::vector<TCoordinates::Coordinates> seen;

  for (char c : lines[0])
  {
    switch (c)
    {
    case '>':
      if (santasTurn)
        santa.x++;
      else
        robot.x++;
      santasTurn = !santasTurn;
      break;
    case 'v':
      if (santasTurn)
        santa.y--;
      else
        robot.y--;
      santasTurn = !santasTurn;
      break;
    case '<':
      if (santasTurn)
        santa.x--;
      else
        robot.x--;
      santasTurn = !santasTurn;
      break;
    default:
      if (santasTurn)
        santa.y++;
      else
        robot.y++;
      santasTurn = !santasTurn;
    }

    if (!libcontains::contains<TCoordinates::Coordinates>(seen, santa))
    {
      seen.push_back(santa);
      total++;
    }

    if (!libcontains::contains<TCoordinates::Coordinates>(seen, robot))
    {
      seen.push_back(robot);
      total++;
    }
  }

  std::cout << "A total of " << total << " houses received at least one gift" << std::endl;

  return 0;
}