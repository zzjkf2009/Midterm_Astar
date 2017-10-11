/**
*@file Map.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
*@brief This file define two functions of <Map> class
*/

#include "Map.hpp"
#include "Astar.hpp"
#include<array>


Map::gridMatrix Map::getGridmap(const int index) {
        std::array<std::array<int, 10>, 10> gridMap_1 =  {
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
       std::array<std::array<int, 10>, 10> gridMap_2 = {
         {
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1},
            {0,0,0,0,0,0,0,0,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,0,1,1},
            {0,0,0,0,0,0,0,0,1,1},
            {1,1,1,0,0,0,0,1,1,1},
            {1,1,1,1,1,1,1,1,1,1}
          }
         };
        std::array<std::array<int, 10>, 10> gridMap_3 =  {
          {
            {1,1,1,1,1,1,1,1,1,1},
            {1,0,1,1,1,1,1,1,0,1},
            {1,0,1,1,1,1,1,1,0,1},
            {1,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,1},
            {1,0,1,1,1,1,1,1,0,1},
            {1,0,1,1,1,1,1,1,0,1},
            {1,1,1,1,1,1,1,1,1,1}
          }
           };

         switch (index) {
           case 1 :
                return gridMap_1;
                break;
           case 2 :
                return gridMap_2;
                break;
           case 3 :
                return gridMap_3;
                break;
           default :
            return  gridMap_1;
         }
}





/**
*@brief This function read two integar and make them as the 2D coordinate of the
*       node
*@param x and y, both are int, which represent the location of the start node
*@return coordinate pair<x,y>
*/
Astar::coordinate Map::SetStart(const int& x, const int& y) {
  return std::make_pair(x, y);
}
/**
*@brief Same as last funtion, it returns the coordinate of goal node
*@param two integars x and y
*@return coordinate pair<x,y>
*/
Astar::coordinate Map::SetGoal(const int& x, const int& y) {
  return std::make_pair(x, y);
}
