/**
   *@file BuildingMap.hpp
   *@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license, please visit :
   https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
 **@brief This header define the <Buildingmap> calss, which is to draw the grid
 *       map by using OpenCV
 */
#ifndef INCLUDE_BUILDINGMAP_H_
#define INCLUDE_BUILDINGMAP_H_

#include <opencv2/opencv.hpp>
#include <stack>
static const int ROW = 10;
static const int COL = 10;

class Buildingmap {
public:
typedef std::pair<int, int> coordinate;
typedef std::array<std::array<int, ROW>, COL> gridMatrix;
/**
   *@brief Funtion that draw the grid map by using Opencv, walls will be black
 *       start and goal node are RGB[0,255,255]
 **@param  <grid> a matrix created using array of array
 **@param <goal> corrdinate of goal in pair
 **@return cv::Mat, an image(matrix) show map including walls, start, goal node
 */
cv::Mat drawGrids(gridMatrix grid, coordinate start,
                  coordinate goal);
/**
   *@brief Funtion that draw the path node which are RGB[0,255,255]
   *@param <Path> nodes in stack <coordinate>
   *param <Background> map image , in cv::Mat
   *@return cv::Mat, an image show map including walls, start, goal node anb path
 */
cv::Mat drawPath(std::stack<coordinate> Path, cv::Mat Background);
};

#endif  // INCLUDE_BUILDINGMAP_H_
