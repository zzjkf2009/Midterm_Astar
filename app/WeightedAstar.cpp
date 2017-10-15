/**
*@file WeightedAstar.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This source file define a funtion of <WeightedAstar> calss
*/
#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include"WeightedAstar.hpp"
#include"Astar.hpp"
#include"Map.hpp"
#include<cmath>
#include<cstring>
#include<utility>

/**
*brief Funtion that generate a path from start to goal ndoe by using a
*      path planing algorithm called WeightedAstar
*@param int grid[10][10], a 10 by 10 grid map, locaion of start and goal
*       node, weight , an integar
*@return stack <coordinate> lolation of the path node
*/
std::stack<Astar::coordinate> WeightedAstar::WeightedA(Map::gridMatrix grid,
                                                       coordinate start,
                                                       coordinate goal,
                                                       const int& weight) {
  if (isValid(start.first, start.second) == false) {
    printf("start node is invalid\n");
    return std::stack<Astar::coordinate>();
  }
  if (isValid(goal.first, goal.second) == false) {
    printf("Goal node is invalid");
    return std::stack<Astar::coordinate>();
  }
  if (isUnblocked(grid, start.first, start.second) == false
      || isUnblocked(grid, goal.first, goal.second) == false) {
    printf("Start or gaol node is blocked");
    return std::stack<Astar::coordinate>();
  }
  if (isGoalNode(start.first, start.second, goal) == true) {
    printf("Start node and goal node are same");
    return std::stack<Astar::coordinate>();
  }
  /*@ Create a close list and initial it to f*/
  bool closedList[ROW][COL];
  memset(closedList, false, sizeof(closedList));
  node nodeinfo[ROW][COL];
  /*@ Declare a array to hold the info of every nodes*/
  int i, j;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      nodeinfo[i][j].F = FLT_MAX;
      nodeinfo[i][j].H = FLT_MAX;
      nodeinfo[i][j].G = FLT_MAX;
      nodeinfo[i][j].parent_x = -1;
      nodeinfo[i][j].parent_y = -1;
    }
  }
  /*@ initialising the parameters of the starting node*/
  i = start.first;
  j = start.second;
  nodeinfo[i][j].F = 0.0;
  nodeinfo[i][j].H = 0.0;
  nodeinfo[i][j].G = 0.0;
  nodeinfo[i][j].parent_x = i;
  nodeinfo[i][j].parent_y = j;
  /*@ Create a open List which has the info of <F, <i,j>>
   where f=G+weight*H    */
  std::set<Open_list> openList;
  /* put start node into openList*/
  openList.insert(std::make_pair(0.0, std::make_pair(i, j)));
  bool foundGoal = false;
  while (!openList.empty()) {
  Open_list p = *openList.begin();
  for (const auto& n :openList) {
    if (n.first < p.first)
        p = n;
  }
    openList.erase(p);
    i = p.second.first;
    j = p.second.second;
    closedList[i][j] = true;
    /* Generating all of the 8 sucessor node around the current node */
    double Gnew, Hnew, Fnew;
    std::vector<int> sucessor_x = { -1, 0, 1 };
    std::vector<int> sucessor_y = { -1, 0, 1 };
// For every node near the current node, top, top-left, top-right, left, right,
// bottom, bottom-left, bottom-right
    std::stack<coordinate> PathOut;
    for (const auto& k : sucessor_x) {
      for (const auto& l : sucessor_y) {
        if (k == 0 && l == 0)
          continue;
        if (isValid(i + k, j + l) == true) {
          if (isGoalNode(i + k, j + l, goal) == true) {
            nodeinfo[i + k][j + l].parent_x = i;
            nodeinfo[i + k][j + l].parent_y = j;
            std::printf("The goal node is found\n");
            PathOut = GeneratePath(nodeinfo, goal);
            foundGoal = true;
            return PathOut;
          } else if (closedList[i + k][j + l] == false
              && isUnblocked(grid, i + k, j + l) == true) {
            Gnew = nodeinfo[i][j].G + sqrt(k * k + l * l);
            Hnew = calculate_H(i + k, j + l, goal);
            Fnew = Gnew + weight * Hnew;
            if (nodeinfo[i + k][j + l].F == FLT_MAX
                || nodeinfo[i + k][j + l].F > Fnew) {
              openList.insert(
                  std::make_pair(Fnew, std::make_pair(i + k, j + l)));
              nodeinfo[i + k][j + l].F = Fnew;
              nodeinfo[i + k][j + l].G = Gnew;
              nodeinfo[i + k][j + l].H = Hnew;
              nodeinfo[i + k][j + l].parent_x = i;
              nodeinfo[i + k][j + l].parent_y = j;
            }
          }
        }
      }
    }
  }
  if (foundGoal == false)
    printf(" Failed to find th goal node");
  return std::stack<Astar::coordinate>();
}
