/**
*@file Astar.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
*@brief This file define several functions of <Astar> class
*
*/
#include<iostream>
#include<stack>
#include<cmath>
#include"Astar.hpp"




bool Astar::isValid(const int& x, const int& y) {
  return ((x >= 0) && (x < ROW) && (y >= 0) && (y < COL));
}

bool Astar::isUnblocked(gridMatrix grid, const int& x, const int& y) {
  if (grid[x][y] == 1)
    return true;
  else
    return false;
}

bool Astar::isGoalNode(const int& x, const int& y, coordinate goal) {
  if (x == goal.first && y == goal.second)
    return true;
  else
    return false;
}

double Astar::calculate_H(const int& x, const int& y, coordinate goal) {
  return  sqrt(
      (x - goal.first) * (x - goal.first)
          + (y - goal.second) * (y - goal.second));
}

std::stack<Astar::coordinate> Astar::GeneratePath(node nodepath[][COL],
                                           coordinate goal) {
  printf("The path is  \n");
  int x = goal.first;
  int y = goal.second;
  std::stack<coordinate> Path;
  std::stack<coordinate> PathOut;
  while (!(nodepath[x][y].parent_x == x && nodepath[x][y].parent_y == y)) {
    Path.push(std::make_pair(x, y));
    int temp_x = nodepath[x][y].parent_x;
    int temp_y = nodepath[x][y].parent_y;
    x = temp_x;
    y = temp_y;
  }
  Path.push(std::make_pair(x, y));
  PathOut = Path;
  while (!Path.empty()) {
    std::pair<int, int> p = Path.top();
    Path.pop();
    printf("---->>>> (%d,%d) ", p.first, p.second);
  }
  return PathOut;
}
