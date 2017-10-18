/**
*@file AstaralgoMock.hpp
*@Copyright (C) 2017 Zejiang Zeng - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the MIT license, please visit :
 https://github.com/zzjkf2009/Midterm_Astar/blob/master/LICENSE
*@brief This header file that specifies calling conventions for cock functions
* for Astaralgo class
*/
#include "Astaralgo.hpp"
#include "gmock/gmock.h"
using ::testing::Return;
class AstaralgoMock : public virtual Astaralgo {
 public:
  MOCK_METHOD2(isValid, bool(const int& x, const int& y));
  MOCK_METHOD3(isUnblocked, bool(Astaralgo::gridMatrix grid, const int& x, const int& y));
  MOCK_METHOD3(isGoalNode, bool(const int& x, const int& y, Astaralgo::coordinate goal));
  MOCK_METHOD3(calculate_H, double(const int& x, const int& y, Astaralgo::coordinate goal));
  MOCK_METHOD2(GeneratePath, std::stack<Astaralgo::coordinate>(Astaralgo::node nodepath[][COL], Astaralgo::coordinate goal));
};
