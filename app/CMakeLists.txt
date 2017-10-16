add_executable(shell-app main.cpp Astar.cpp Map.cpp WeightedAstar.cpp BuildingMap.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries( shell-app ${OpenCV_LIBS})
