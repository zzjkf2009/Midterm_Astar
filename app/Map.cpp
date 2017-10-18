/**
*@file Map.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
*@brief This file define two functions of <Map> class
*/

#include "Map.hpp"
#include<array>


Map::gridMatrix Map::getGridmap(const int& index) {
        Map::gridMatrix gridMap_1 =  {
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
       Map::gridMatrix gridMap_2 = {
         {
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1},
            {0,0,0,0,0,0,0,0,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1},
            {0,0,0,0,0,0,0,0,1,1},
            {1,1,1,0,0,0,0,1,1,1},
            {1,1,1,1,1,1,1,1,1,1}
          }
         };
        Map::gridMatrix gridMap_3 =  {
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
           Map::gridMatrix gridMap_4 =  {
             {
               {1,1,1,1,1,1,1,1,1,1},
               {1,1,1,1,1,1,1,1,1,1},
               {1,1,1,1,1,1,1,1,1,1},
               {1,1,1,1,1,1,1,1,1,1},
               {1,1,1,1,1,1,1,1,1,1},
               {0,0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1,1},
               {1,1,1,1,1,1,1,1,1,1},
               {1,1,1,1,1,1,1,1,1,1},
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
           case 4:
                return gridMap_4;
                break;
           default :
                return  gridMap_1;
         }
}

Map::coordinate Map::SetStart(const int& x, const int& y) {
  return std::make_pair(x, y);
}

Map::coordinate Map::SetGoal(const int& x, const int& y) {
  return std::make_pair(x, y);
}
