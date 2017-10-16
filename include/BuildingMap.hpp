/**
*@file BuildingMap.h
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This header define the <Buildingmap> calss, which is to draw the grid
*       map
*/
#ifndef INCLUDE_BUILDINGMAP_H_
#define INCLUDE_BUILDINGMAP_H_

#include <opencv2/opencv.hpp>
#include<cmath>
#include<stack>
#include"Astar.hpp"
#include"Map.hpp"
#define ROW 10
#define COL 10

class Buildingmap {
 public:
  cv::Mat drawGrids(Map::gridMatrix grid, Astar::coordinate start,
                    Astar::coordinate goal);
  cv::Mat drawPath(std::stack<Astar::coordinate> Path, cv::Mat Background);
};

#endif  // INCLUDE_BUILDINGMAP_H_
