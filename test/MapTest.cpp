#include <gtest/gtest.h>
#include <array>
#include <memory>
#include "Map.hpp"


struct MapTest : public :: testing :: Test{
std::shared_ptr<Map> setmap = std::make_shared<Map>();
};


TEST_F(MapTest, LoadMapSwitchTest) {
    EXPECT_EQ(10,(setmap->getGridmap(1)).size());
    EXPECT_FALSE((setmap->getGridmap(1)).empty());
    EXPECT_FALSE((setmap->getGridmap(2)).empty());
    EXPECT_FALSE((setmap->getGridmap(3)).empty());
    EXPECT_FALSE((setmap->getGridmap(4)).empty());
}


TEST_F(MapTest, SetstartTest) {
    EXPECT_EQ(std::make_pair(2, 3),setmap->SetStart(2,3));
}


TEST_F(MapTest, SetgoalTest) {
    EXPECT_EQ(std::make_pair(4, 6),setmap->SetGoal(4,6));
}
