#include <iostream>
#include <array>
#include <iostream>
#include "Astar.hpp"
#include "Map.hpp"
#include "WeightedAstar.hpp"
int main()
{


   Map setmap;
   Map::gridMatrix map_info = setmap.getGridmap(3);
   Astar::coordinate start = setmap.SetStart(0, 4);
   Astar::coordinate goal = setmap.SetGoal(9, 5);
   std::stack<Astar::coordinate> Path;
   int weight = 2;
   WeightedAstar w_astar;
   Path = w_astar.WeightedA(map_info, start, goal, weight);
   return 0;
}
