#pragma once
#include <deque>

struct Point {
  int x, y;
};

enum class Direction { UP, DOWN, LEFT, RIGHT, NONE };

class Snake {
private:
  std::deque<Point> body;
  Direction currentDir;

public:
  Snake(int startX, int startY);

  void setDirection(Direction dir);
  Direction getDirection() const;

  // Move (grow determines if tail is kept)
  void move(bool grow = false);

  // Collision check
  bool checkCollision(int width, int height) const;

  // Get head position
  Point getHead() const;

  // Get full body (for rendering)
  const std::deque<Point> &getBody() const;
};