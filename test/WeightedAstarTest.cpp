/**
 *@file WeightedAstarTest.cpp
 *@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
 *@brief This unit test source file will test if the method in class WeightedAstar 
 *is working as expected by using gmock
 */
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "AstaralgoMock.hpp"
#include "WeightedAstar.hpp"
#include <memory>

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Eq;
using ::testing::Ne;
using ::testing::Ge;
using ::testing::Le;

/**
 *@brief Using Gmock in unit test for a derived class WeightedAstar, set  expectations on the mock objects, and use them to verify if the method WeightedA in WeightedAstar class works as expected, when
 map and sart, goal node are given
 */
struct WeightedAstarTest : public ::testing::Test {
  std::shared_ptr<WeightedAstar> weighted = std::make_shared<WeightedAstar>();
};

TEST_F(WeightedAstarTest, WeightedATest) {

  AstaralgoMock Astarmock;

  EXPECT_CALL(Astarmock, isValid(Le(10),Le(10))).Times(AtLeast(1))
      .WillRepeatedly(Return(true));

  EXPECT_CALL(Astarmock, isUnblocked(_,_,_)).Times(AtLeast(1)).WillOnce(
      Return(false)).WillRepeatedly(Return(true));

  EXPECT_CALL(Astarmock, isGoalNode(Eq(7),Eq(8),_)).WillRepeatedly(
      Return(true));

  EXPECT_CALL(Astarmock, isGoalNode(Ne(7),Ne(8),_)).WillRepeatedly(
      Return(false));

  EXPECT_CALL(Astarmock, calculate_H(_,_,_)).WillRepeatedly(Return(10));
  Astar::gridMatrix gridMap =  {
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
  Astar::coordinate start = std::make_pair(2, 3);
  Astar::coordinate goal = std::make_pair(7, 8);
  Astar::coordinate path_node1 = std::make_pair(2, 3);
  Astar::coordinate path_node2 = std::make_pair(3, 4);
  Astar::coordinate path_node3 = std::make_pair(5, 6);
  std::stack < Astar::coordinate > path;
  path.push(path_node1);
  path.push(path_node2);
  path.push(path_node3);
  EXPECT_CALL(Astarmock, GeneratePath(_,_)).Times(AtLeast(1)).WillRepeatedly(
      Return(path));

  EXPECT_FALSE((weighted->WeightedA(gridMap, start, goal, 5)).empty());

  Astar::coordinate Badgoal = std::make_pair(9, 9);

  EXPECT_FALSE((weighted->WeightedA(gridMap, start, Badgoal, 5)).empty());

}

