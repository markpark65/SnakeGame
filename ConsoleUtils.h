#pragma once
#include <iostream>
#include <windows.h>


class ConsoleUtils {
public:
  // Move cursor to specific position
  static void gotoXY(int x, int y) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hOut, coord);
  }

  // Hide or show cursor
  static void setCursorVisibility(bool visible) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CurInfo;
    GetConsoleCursorInfo(hOut, &CurInfo); // Get current size
    CurInfo.bVisible = visible;
    SetConsoleCursorInfo(hOut, &CurInfo);
  }

  // Set console title
  static void setConsoleTitle(const char *title) { SetConsoleTitleA(title); }
};
