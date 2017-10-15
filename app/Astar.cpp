/**
*@file Astar.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This file define several functions of <Astar> class
*
*/
#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include"Astar.hpp"
#include"Map.hpp"
#include<cmath>
#include<utility>

/*@brief define a data structure contains two parameters that a node may have */
typedef std::pair<int, int> coordinate;

/**
*@brief Function that checks if the input coordinate is inside the grid map
*@param two integars
*@return ture or false
*/
bool Astar::isValid(const int& x, const int& y) {
  return ((x >= 0) && (x < ROW) && (y >= 0) && (y < COL));
}
/**
*@brief  Function that checks if the grid is a block or wall something like that
*@param  grid[10][10], coordinate x and y, int
*@return boolean ture or false
*/
bool Astar::isUnblocked(Map::gridMatrix grid, const int& x, const int& y) {
  if (grid[x][y] == 1)
    return true;
  else
    return false;
}
/**
*@  Funtion that checks if it is the goal node
*@param two int x and y, goal coordinate
*@return boolean,ture or false
 */
bool Astar::isGoalNode(const int& x, const int& y, coordinate goal) {
  if (x == goal.first && y == goal.second)
    return true;
  else
    return false;
}
/**
*@brief  Function that calculates the heuristic value between current node and
*goal node method usd here is Eucliden Distance. Other method like Diagnal
* Distance or Manhattan Distance are also appliable
*@param two int x and y, coordinate of gaol
*@return doule
*/
double Astar::calculate_H(const int& x, const int& y, coordinate goal) {
  return  sqrt(
      (x - goal.first) * (x - goal.first)
          + (y - goal.second) * (y - goal.second));
}
/**
*@brief Function that will generate the path back from goal node to the start node
 and the path of the nodes will displayed on the screen
*@param nodepath and goal coordinate
*@return stack<coordinate>
 */
std::stack<coordinate> Astar::GeneratePath(node nodepath[][COL],
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
