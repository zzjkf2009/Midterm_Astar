#include <iostream>
#include <array>
#include <iostream>
#include "Astar.hpp"
#include "Map.hpp"
int main()
{

   int x = 1;
   Map map;

Map::gridMatrix map_info = map.getGridmap(x);


std::cout<<map_info[1][1]<<std::endl;

    return 0;
}
