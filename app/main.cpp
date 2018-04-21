/**
 * @Author: Zejiang Zeng <yzy>
 * @Date:   2018-03-12T20:29:41-04:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Filename: main.cpp
 * @Last modified by:   yzy
 * @Last modified time: 2018-03-27T09:21:10-04:00
 * @Copyright: (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 */

#include <iostream>
#include <array>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Astar.hpp"
#include "Map.hpp"
#include "BuildingMap.hpp"
#include "WeightedAstar.hpp"
#include "dstar.h"
int main() {
        Map setmap;
        Map::gridMatrix map_info = setmap.getGridmap(3);
        Astar::coordinate start = setmap.SetStart(2, 3);
        Astar::coordinate goal = setmap.SetGoal(7, 7);
        Buildingmap build;
        cv::Mat Map = build.drawGrids(map_info, start, goal);
        // #############################
        Dstar dstar(start.first,start.second,goal.first,goal.second);
        bool check = dstar.replan();
        if (check)
                std::cout<<"Find the goal"<<std :: endl;
        cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
        cv::imshow( "Display window", Map);
        cv::waitKey(10000);
        return 0;
}
