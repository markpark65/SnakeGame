#include "Game.h"
#include "ConsoleUtils.h"
#include <conio.h> // _kbhit(), _getch()
#include <iostream>
#include <windows.h> // Sleep()

using namespace std;

Game::Game() : isGameOver(false), score(0), speed(100) {
  // Smart pointers initialize new objects
  snake = std::make_unique<Snake>(10, 10);
  map = std::make_unique<Map>(20, 20);
  map->spawnFood(*snake);
}

Game::~Game() {
  // Smart pointers clean up automatically
}

void Game::handleInput() {
  if (_kbhit()) {
    char key = _getch();
    switch (tolower(key)) {
    case 'w':
      snake->setDirection(Direction::UP);
      break;
    case 's':
      snake->setDirection(Direction::DOWN);
      break;
    case 'a':
      snake->setDirection(Direction::LEFT);
      break;
    case 'd':
      snake->setDirection(Direction::RIGHT);
      break;
    case 'q':
      isGameOver = true;
      break;
    }
  }
}

void Game::run() {
  // Hide cursor
  ConsoleUtils::setCursorVisibility(false);
  ConsoleUtils::setConsoleTitle("Snake Game - Portfolio");

  while (!isGameOver) {
    handleInput();

    // Game Logic
    bool eat = false;
    Point head = snake->getHead();
    Direction dir = snake->getDirection();
    Point nextPos = head;

    switch (dir) {
    case Direction::UP:
      nextPos.y--;
      break;
    case Direction::DOWN:
      nextPos.y++;
      break;
    case Direction::LEFT:
      nextPos.x--;
      break;
    case Direction::RIGHT:
      nextPos.x++;
      break;
    case Direction::NONE:
      break;
    }

    Point food = map->getFoodPos();

    // Check food collision logic
    if (nextPos.x == food.x && nextPos.y == food.y) {
      eat = true;
      score += 10;
      map->spawnFood(*snake);
      // Increase speed logic
      if (speed > 20)
        speed -= 2;
    }

    snake->move(eat);

    // Check wall/self collision
    if (snake->checkCollision(20, 20)) {
      isGameOver = true;
    }

    // Draw
    map->draw(*snake, score);

    // Control speed
    Sleep(speed);
  }

  ConsoleUtils::gotoXY(0, 22);
  cout << "\nGAME OVER! Final Score: " << score << endl;
  cout << "Press any key to exit..." << endl;

  // Clear buffer
  while (_kbhit())
    _getch();
  _getch();
}