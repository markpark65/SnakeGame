#include "Map.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <string>


using namespace std;

Map::Map(int w, int h)
    : width(w), height(h), rng(std::random_device{}()), distX(1, width - 2),
      distY(1, height - 2) {
  spawnFood(Snake(0, 0)); // Initial spawn (Snake position doesn't matter much
                          // here as long as it's not random)
}

void Map::spawnFood(const Snake &snake) {
  bool onSnake = true;
  while (onSnake) {
    onSnake = false;
    foodPos.x = distX(rng);
    foodPos.y = distY(rng);

    for (const auto &part : snake.getBody()) {
      if (part.x == foodPos.x && part.y == foodPos.y) {
        onSnake = true;
        break;
      }
    }
  }
}

void Map::draw(const Snake &snake, int score) {
  // Prevent cursor flickering
  ConsoleUtils::gotoXY(0, 0);

  string buffer = "";
  buffer.reserve((width + 1) * height +
                 100); // Reserve memory to avoid reallocations

  buffer += "====================\n";
  buffer += "  Snake Game (C++)  \n";
  buffer += "====================\n";

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
        buffer += "#"; // Wall
      } else if (x == foodPos.x && y == foodPos.y) {
        buffer += "*"; // Food
      } else {
        bool isBody = false;
        // Check if this position is part of the snake
        for (const auto &part : snake.getBody()) {
          if (part.x == x && part.y == y) {
            if (part.x == snake.getHead().x && part.y == snake.getHead().y) {
              buffer += "O"; // Head
            } else {
              buffer += "o"; // Body
            }
            isBody = true;
            break;
          }
        }
        if (!isBody)
          buffer += " ";
      }
    }
    buffer += "\n";
  }
  buffer += " Score: " + to_string(score) + "\n";

  cout << buffer;
}

Point Map::getFoodPos() const { return foodPos; }