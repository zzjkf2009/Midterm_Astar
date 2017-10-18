/**
 *@file AstarTest.cpp
 *@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
 *@brief This unit test source file will test if the method in class Astar 
 *is working as expected
 */
#include <gtest/gtest.h>
#include <memory>
#include"Astar.hpp"

struct AstarTest : public ::testing::Test {
  std::shared_ptr<Astar> astar = std::make_shared<Astar>();
};

/**
 *@brief This test will verify if a node is inside or outside of the map 
 */
TEST_F(AstarTest, isValidTest) {
  EXPECT_FALSE(astar->isValid(2, -1));
  EXPECT_FALSE(astar->isValid(-1, -2));
  EXPECT_FALSE(astar->isValid(11, 1));
  EXPECT_FALSE(astar->isValid(1, 11));
  EXPECT_TRUE(astar->isValid(5, 5));
}


/**
*@brief Given a specific map,  for some specifc node,verify if it is a block or not
*/
TEST_F(AstarTest, isUnblockedTest) {
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
   EXPECT_FALSE(astar->isUnblocked(gridMap,1, 2));
   EXPECT_TRUE(astar->isUnblocked(gridMap,5, 5));
}

/**
 *@brief Given a specific goal,  for a specifc node, verify if it is the goal node
 */
TEST_F(AstarTest, isGoalNodeTest) {
Astar::coordinate goal = std::make_pair(2, 3);
EXPECT_FALSE(astar->isGoalNode(1, 2,goal));
EXPECT_TRUE(astar->isGoalNode(2, 3,goal));
}
/**
 *@brief Given a specific goal,  for a specifc node, verify if the H value is calculated correctly
 */
TEST_F(AstarTest, calculate_HTest) {
Astar::coordinate goal = std::make_pair(2, 3);
EXPECT_EQ(5,astar->calculate_H(5,7,goal));
}


