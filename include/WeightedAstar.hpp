/**
*@file WeightedAstar.hpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
*@brief This header define the <WeightedAstar> calss, which is the derive class
*       of the <Astar> class, it is the main part to implenment the searching algorithm
*/

#ifndef INCLUDE_WEIGHTEDASTAR_H_
#define  INCLUDE_WEIGHTEDASTAR_H_

#include<stack>
#include"Astar.hpp"


class WeightedAstar : public Astar {
 public:
/**
*brief Funtion that generate a path from start to goal ndoe by using one
*      path planing algorithm called WeightedAstar
*@param  <grid> a matrix created using array of array
*@param <x> int x coordinate
*@param <y> int y coordinatesss
*param <weight> int weight of the heuristic value
*@return stack <coordinate> lolation of the path node
*/
  std::stack<coordinate> WeightedA(gridMatrix grid, coordinate start,
                                   coordinate goal, const int& weight);
};
#endif  // INCLUDE_WEIGHTEDASTAR_H_
