/**
*@file BuildingMapTest.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
*@brief This unit test source file will test if the method in class BuildingMap 
*is working as expected
*/
#include <gtest/gtest.h>
#include <memory>
#include<stack>
#include <opencv2/opencv.hpp>
#include "BuildingMap.hpp"


struct BuildingMapTest : public :: testing :: Test{
std::shared_ptr<Buildingmap> drawmap = std::make_shared<Buildingmap>();
};
/**
*@brief Given a specific map and start, goal node,verify if it can be draw 
*/
TEST_F(BuildingMapTest, drawGridsTest) {
      Buildingmap::gridMatrix gridMap =  {
        {
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,0,0,0,0,0,0,1,1},
            {1,1,1,1,1,1,1,0,1,1},
            {1,1,1,1,1,1,1,0,1,1},
            {1,1,1,1,1,1,1,0,1,1},
            {1,1,1,1,1,1,1,0,1,1},
            {1,1,1,1,1,1,1,0,1,1},
            {1,1,0,0,0,0,0,0,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1}
          }
          };
Buildingmap::coordinate start = std::make_pair(2, 3);
Buildingmap::coordinate goal = std::make_pair(7, 8);
    EXPECT_FALSE((drawmap->drawGrids(gridMap,start,goal)).empty());
}

/**
*@brief Given a specific map and path ,verify if it can be draw 
*/
TEST_F(BuildingMapTest, drawPathTest) {
     Buildingmap::coordinate path_node1 = std::make_pair(2, 3);
     Buildingmap::coordinate path_node2 = std::make_pair(3, 4);
     Buildingmap::coordinate path_node3 = std::make_pair(5, 6);
     std::stack<Buildingmap::coordinate> path;
     path.push(path_node1); path.push(path_node2); path.push(path_node3);
     cv::Mat Background = cv::Mat::zeros(100, 100, CV_8UC3);
     EXPECT_FALSE((drawmap->drawPath(path,Background)).empty());
}
