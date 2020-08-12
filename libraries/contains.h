#pragma once
#include <vector>
#include "../types/coordinates.h"

namespace libcontains
{
  bool operator==(TCoordinates::Coordinates c1,
                  TCoordinates::Coordinates c2)
  {
    return c1.x == c2.x && c1.y == c2.y;
  }

  template <class T>
  bool contains(std::vector<T> container, T element)
  {
    for (T el : container)
    {
      if (el == element)
        return true;
    }
    return false;
  }
} // namespace libcontains