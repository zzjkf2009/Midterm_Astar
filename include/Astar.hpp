/**
*@file WeightedAstar.hpp
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
#include<stack>
#include<limits>
#include<array>


class Astar {
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
/**
*@brief Method that checks if the input coordinate is inside the grid map
*@param int <x> location at x axis 
*@param int <y>, location at y axis
*@return bool type ture or false
*/
  bool isValid(const int& x, const int& y);
/**
*@brief  Method that checks if the grid is a block or wall something like that
*@param  <grid> a matrix created using array of array
*@param <x> int x coordinate 
*@param <y> int y coordinatesss
*@return bool ture or false
*/
  bool isUnblocked(gridMatrix grid, const int& x, const int& y);
/**
*@brief  Method that checks if the current node is the goal node
*@param <goal> corrdinate of goal in pair
*@param <x> int x coordinate 
*@param <y> int y coordinatesss
*@return bool ture or false
*/
  bool isGoalNode(const int& x, const int& y, coordinate goal);
/**
*@brief  Function that calculates the heuristic value between current node and
*goal node method usd here is Eucliden Distance. Other method like Diagnal
* Distance or Manhattan Distance are also appliable
*@param <x> int x coordinate 
*@param <y> int y coordinate
*@param <goal> corrdinate of goal in pair
*@return doule f value
*/
  double calculate_H(const int& x, const int& y, coordinate goal);
/**
*@brief Function that will generate the path back from goal node to the start node
 and the path of the nodes will displayed on the screen
*@param <node> the path in terms of each node location
*@param <goal> goal coordinate
*@return stack<coordinate>
 */
  std::stack<coordinate> GeneratePath(node nodepath[][COL], coordinate goal);
};

#endif  // INCLUDE_ASTAR_H_
