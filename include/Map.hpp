/**
*@file Map.h
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This header define the <Map> calss, which is to read start and goal node
*/

#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_


#include<utility>
#include<array>
class Map{
 public:
typedef std::array<std::array<int, 10>, 10> gridMatrix;
typedef std::pair<int, int> coordinate;
gridMatrix getGridmap(const int index);
coordinate SetStart(const int& x, const int& y);
coordinate SetGoal(const int& x, const int& y);
};

#endif  // INCLUDE_MAP_H_
