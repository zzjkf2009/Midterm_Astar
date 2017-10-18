/**
 *@file main.cpp
 *@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
 *@brief This is the main source file that combine the Astar path palng project 
 */
#include <iostream>
#include <array>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Astar.hpp"
#include "Map.hpp"
#include"BuildingMap.hpp"
#include "WeightedAstar.hpp"
int main() {
  Map setmap;
  Map::gridMatrix map_info = setmap.getGridmap(3);
  Astar::coordinate start = setmap.SetStart(2, 3);
  Astar::coordinate goal = setmap.SetGoal(7, 7);
  std::stack < Astar::coordinate > Path;
  int weight = 2;
  WeightedAstar w_astar;
  Path = w_astar.WeightedA(map_info, start, goal, weight);
  Buildingmap build;
  cv::Mat Map = build.drawGrids(map_info, start, goal);
  cv::Mat PathIm = build.drawPath(Path, Map);
  if (!PathIm.data)                              // Check for invalid input
  {
    std::cout << "Could not open or find the image" << std::endl;
    return -1;
  }
  imwrite("Image.jpg", PathIm);
  return 0;
}

