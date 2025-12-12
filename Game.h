#pragma once
#include "Map.h"
#include "Snake.h"
#include <memory>


class Game {
private:
  std::unique_ptr<Snake> snake;
  std::unique_ptr<Map> map;
  bool isGameOver;
  int score;
  int speed;

  void handleInput();

public:
  Game();
  ~Game(); // Smart pointers handle cleanup, but we might want a specific dtor
           // or default
  void run();
};