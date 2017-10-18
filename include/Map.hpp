/**
*@file Map.hpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This header define the <Map> calss, which is to select a pre-defined grid map and read start, goal node
*/

#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_


#include<utility>
#include<array>

class Map{
 public:
typedef std::array<std::array<int, 10>, 10> gridMatrix;
typedef std::pair<int, int> coordinate;
/**
*@brief This method is to choose a self-defined grid map
*@param <index> int a index of the grid map
*@return a matrix of the map built by array of array
*/
gridMatrix getGridmap(const int& index);
/**
*@brief This function read two integar and make them as the 2D coordinate of the
*       node
*@param int <x> location at x axis 
*@param int <y>, location at y axis
*@return coordinate pair<x,y>
*/
coordinate SetStart(const int& x, const int& y);
/**
*@brief Same as last funtion, it returns the coordinate of goal node
*@param int <x> location at x axis 
*@param int <y>, location at y axis
*@return coordinate pair<x,y>
*/
coordinate SetGoal(const int& x, const int& y);
};

#endif  // INCLUDE_MAP_H_
