add_executable(shell-app main.cpp Astar.cpp Map.cpp WeightedAstar.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
