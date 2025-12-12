#include "Snake.h"

Snake::Snake(int startX, int startY) {
  // Initial length 3
  body.push_back({startX, startY});
  body.push_back({startX, startY + 1});
  body.push_back({startX, startY + 2});
  currentDir = Direction::UP;
}

void Snake::setDirection(Direction dir) {
  // Prevent 180 degree turns
  if ((currentDir == Direction::UP && dir == Direction::DOWN) ||
      (currentDir == Direction::DOWN && dir == Direction::UP) ||
      (currentDir == Direction::LEFT && dir == Direction::RIGHT) ||
      (currentDir == Direction::RIGHT && dir == Direction::LEFT)) {
    return;
  }
  currentDir = dir;
}

Direction Snake::getDirection() const { return currentDir; }

void Snake::move(bool grow) {
  if (currentDir == Direction::NONE)
    return;

  Point newHead = body.front();

  switch (currentDir) {
  case Direction::UP:
    newHead.y--;
    break;
  case Direction::DOWN:
    newHead.y++;
    break;
  case Direction::LEFT:
    newHead.x--;
    break;
  case Direction::RIGHT:
    newHead.x++;
    break;
  case Direction::NONE:
    break;
  }

  body.push_front(newHead); // Add new head

  if (!grow) {
    body.pop_back(); // Remove tail if not growing
  }
}

bool Snake::checkCollision(int width, int height) const {
  if (body.empty())
    return false;

  Point head = body.front();

  // 1. Wall collision
  if (head.x <= 0 || head.x >= width - 1 || head.y <= 0 || head.y >= height - 1)
    return true;

  // 2. Self collision
  for (size_t i = 1; i < body.size(); ++i) {
    if (head.x == body[i].x && head.y == body[i].y)
      return true;
  }
  return false;
}

Point Snake::getHead() const { return body.front(); }

const std::deque<Point> &Snake::getBody() const { return body; }