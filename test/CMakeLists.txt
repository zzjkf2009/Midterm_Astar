set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    MapTest.cpp
    ../app/Map.cpp
    AstarTest.cpp
    ../app/Astar.cpp
    BuildingMapTest.cpp
   ../app/BuildingMap.cpp
  #  WeightedAstarTest.cpp
  #../app/WeightedAstar.cpp
)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)


target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ../vendor/googletest/googlemock/include
                                           ${CMAKE_SOURCE_DIR}/include)
#target_link_libraries(cpp-test PUBLIC gtest gmock ${OpenCV_LIBS})
target_link_libraries(cpp-test PUBLIC  gmock_main ${OpenCV_LIBS})
