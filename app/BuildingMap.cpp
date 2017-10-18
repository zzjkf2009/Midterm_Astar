/**
*@file BuildingMap.cpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
*@brief This source file defines two functions of <BuildingMap> class
*/
#include <opencv2/opencv.hpp>
#include<stack>
#include"BuildingMap.hpp"





cv::Mat Buildingmap::drawGrids(Buildingmap::gridMatrix grid, Buildingmap::coordinate start,
                               Buildingmap::coordinate goal) {
  int image_x = ROW * 10;
  int image_y = COL * 10;
  cv::Mat Background = cv::Mat::zeros(image_x, image_y, CV_8UC3);

  int i, j;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      if (grid[i][j] == 0)
        continue;
      cv::rectangle(Background, cv::Point(i * 10, j * 10),
                    cv::Point((i + 1) * 10, (j + 1) * 10),
                    cv::Scalar(255, 255, 0), -1, 8);
    }
  }

  int start_i = start.first;
  int start_j = start.second;
  int goal_i = goal.first;
  int goal_j = goal.second;
  cv::rectangle(Background, cv::Point(start_i * 10, start_j * 10),
                cv::Point((start_i + 1) * 10, (start_j + 1) * 10),
                cv::Scalar(0, 255, 0), -1, 8);
  cv::rectangle(Background, cv::Point(goal_i * 10, goal_j * 10),
                cv::Point((goal_i + 1) * 10, (goal_j + 1) * 10),
                cv::Scalar(0, 255, 0), -1, 8);

  return Background;
}


cv::Mat Buildingmap::drawPath(std::stack<coordinate> Path, cv::Mat Background) {
// Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
  cv::VideoWriter video("outcpp.avi",CV_FOURCC('M','J','P','G'),10, cv::Size(100,100));
  while (!Path.empty()) {
    std::pair<int, int> p = Path.top();
    int i = p.first;
    int j = p.second;
    cv::rectangle(Background, cv::Point(i * 10, j * 10),
                  cv::Point((i + 1) * 10, (j + 1) * 10),
                  cv::Scalar(0, 255, 255), -1, 8);

    // Write the frame into the file 'outcpp.avi'
    video.write(Background);
    Path.pop();
  }
  // When everything done, release the video capture and write object
  video.release();
  return Background;
}
