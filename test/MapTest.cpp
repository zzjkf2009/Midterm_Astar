/**
 *@file MapTest.cpp
 *@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
 *@brief This unit test source file will test if the method in class Map 
 *is working as expected
 */
#include <gtest/gtest.h>
#include <array>
#include <memory>
#include "Map.hpp"

struct MapTest : public ::testing::Test {
  std::shared_ptr<Map> setmap = std::make_shared<Map>();
};

/**
 *@brief This test will verify if the size of the map is 10-by-10, and for each
 * map, it can laod them properly
 */
TEST_F(MapTest, LoadMapSwitchTest) {
  EXPECT_EQ(10, (setmap->getGridmap(1)).size());
  EXPECT_FALSE((setmap->getGridmap(1)).empty());
  EXPECT_FALSE((setmap->getGridmap(2)).empty());
  EXPECT_FALSE((setmap->getGridmap(3)).empty());
  EXPECT_FALSE((setmap->getGridmap(4)).empty());
}

/**
 *@brief This test will verify if it can set the start node
 */
TEST_F(MapTest, SetstartTest) {
  EXPECT_EQ(std::make_pair(2, 3), setmap->SetStart(2, 3));
}

/**
 *@brief This test will verify if it can set the goal node
 */
TEST_F(MapTest, SetgoalTest) {
  EXPECT_EQ(std::make_pair(4, 6), setmap->SetGoal(4, 6));
}

