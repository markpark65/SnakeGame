#pragma once
#include "Snake.h"
#include <random>
#include <vector>


class Map {
private:
  int width, height;
  Point foodPos;

  // Random number generation
  std::mt19937 rng;
  std::uniform_int_distribution<int> distX;
  std::uniform_int_distribution<int> distY;

public:
  Map(int w, int h);

  void spawnFood(const Snake &snake);
  void draw(const Snake &snake, int score);
  Point getFoodPos() const;
};