/**
*@file WeightedAstar.h
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This header define the <Astar> calss, which is an algorithm for path
*        planning
*/

#ifndef INCLUDE_ASTAR_H_
#define INCLUDE_ASTAR_H_

#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<cmath>
#include<cstring>
#include<utility>
#include "Map.hpp"

class Astar {
 public:
#define ROW 10
#define COL 10
#define FLT_MAX __FLT_MAX__
  struct node {
    int parent_x;
    int parent_y;
    double F, H, G;
  };
  typedef std::pair<int, int> coordinate;
  typedef std::pair<double, std::pair<int, int> > Open_list;
  bool isValid(const int& x, const int& y);
  bool isUnblocked(Map::gridMatrix grid, const int& x, const int& y);
  bool isGoalNode(const int& x, const int& y, coordinate goal);
  double calculate_H(const int& x, const int& y, coordinate goal);
  std::stack<coordinate> GeneratePath(node nodepath[][COL], coordinate goal);
};

#endif  // INCLUDE_ASTAR_H_
