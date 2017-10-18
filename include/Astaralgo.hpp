/**
*@file Astaralgo.hpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
*@brief This header define the virtual <Astaralgo> calss, which will be used to provide a virtual 
* class for gmaock and gtest
*/	
#include<iostream>
#include<stack>
#include<limits>
#include<array>
class Astaralgo {
public:
const double MAX = std::numeric_limits<double>::max();
static const int ROW = 10;
static const int COL = 10;
  struct node {
    int parent_x;
    int parent_y;
    double F, H, G;
  };
  typedef std::pair<int, int> coordinate;
  typedef std::pair<double, std::pair<int, int> > Open_list;
  typedef std::array<std::array<int, 10>, 10> gridMatrix;
virtual ~Astaralgo() {}
virtual bool isValid(const int& x, const int& y) = 0;
virtual bool isUnblocked(gridMatrix grid, const int& x, const int& y) = 0;
virtual bool isGoalNode(const int& x, const int& y, coordinate goal) = 0;
virtual double calculate_H(const int& x, const int& y, coordinate goal) = 0;
virtual std::stack<coordinate> GeneratePath(node nodepath[][COL], coordinate goal) = 0;
};
