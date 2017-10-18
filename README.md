# Acme-Robotics-Project
[![Build Status](https://travis-ci.org/zzjkf2009/Midterm_Astar.svg?branch=master)](https://travis-ci.org/zzjkf2009/Midterm_Astar)
[![Coverage Status](https://coveralls.io/repos/github/zzjkf2009/Midterm_Astar/badge.svg)](https://coveralls.io/github/zzjkf2009/Midterm_Astar)


---
## Overview

This is an exercise project to design a path planning components using high-quality software engineering practices. This project used WeightedA* graph search algorithm to find an optimal path from start node to goal node. User can define the walkable area and walls inside a 10 by 10 grid map. After define start and goal node, it will generate a path. Opencv library was used to draw the map and the path to provide a intuitive graph for user.


---
## Documentation 
### Product backlog

See at: 

https://docs.google.com/spreadsheets/d/1oi0_lRJdbIyyvOXLhlSXE_rxzVVxF54bEYgnyjOvYY4/edit#gid=0 (Public)

---
### Sprint backlog

See at: https://docs.google.com/spreadsheets/d/1J8NyA5U_c-RblC4XINVJP8sTBxEl7IOSfCABVs-cq40/edit#gid=0 (Public)

---
### Iteration backlog
See at: https://docs.google.com/spreadsheets/d/13NoBAFPOcGcF7GGDcg21S123wpvR30cGdjET9HjKRgQ/edit#gid=0 (Public)

---
### Time log
See at: https://docs.google.com/spreadsheets/d/1ps_eQjuyWZXQR849OhGhagHZZerNhdZ-mS-iOgC5uFA/edit#gid=0 (Public)

---
## Prerequisites

* Cmake
---
## Library
* OpenCV
OpenCV is an open source C++ library for image processing and computer vision, originally developed by Intel and now supported by Willow Garage. 
It is a library of many inbuilt functions mainly aimed at real time image processing. Now it has several hundreds of image processing and computer vision algorithms which make developing advanced computer vision applications easy and efficient. More details see: https://docs.opencv.org/2.4/index.html
* Gtest
Google Test is a unit testing library for the C++ programming language, based on the xUnit architecture. More details cna be find at: https://github.com/google/googletest
* Gmock
Google Mock is an extension to Google Test for writing and using C++ mock classes. See the separate Google Mock documentation at https://github.com/google/googletest/blob/master/googlemock/README.md
---
## Installation and Build

Run as fellow:
```
* git clone --recursive https://github.com/zzjkf2009/Midterm_Astar.git
* cd Midterm_Astar
```
If OpenCV library is not cloned with the other file:
```
* git clone https://github.com/opencv/opencv.git
```
And then
```
* mkdir build
* cd build
* cmake ..
* make
```
---
## Running and Demo
Run:
```
cd build
./app/shepp-app
```
If there is a path, the path image and video will be generate in build derectory, meanwhile the path will be printed on the screen. 

* gridMap1:
![](https://github.com/zzjkf2009/Midterm_Astar/blob/master/result/gridMap1.gif)

* gridMap2:
![](https://github.com/zzjkf2009/Midterm_Astar/blob/master/result/gridMap2.gif)

* gridMap3:
![](https://github.com/zzjkf2009/Midterm_Astar/blob/master/result/gridMap3.gif)
---
## Test
After the build process, run the unit test program, you will see the result of all tests
run:
```
./build/test/cpp-test
```
---
## Documentation
follow the instruction below to generate doxygen documentation
before donig it, make sure you install the doxygen by doing
```
$ sudo apt-get install doxygen
$ sudo apt-get install graphviz
```
First, generate a project-specific congfiuration doc
```
$ doxygen -g my_proj.conf 

```
Then modify the congfiuration doc in text editor and specify the root directory that contains the project's source files.
Last, run below to generate html and Latex format files
```
$ doxygen my_proj.conf 
```
---
## Authors
 * **David Pietrocola** *-Initial Framework-* see at: https://github.com/dpiet/cpp-boilerplate.git 
 * **Zejiang Zeng** *-Contributor-* 
---
## LICENSE
* See at https://github.com/zzjkf2009/Midterm_Astar/master/LICENSE
---
## Summary
This project is developed with the following tools:
* IDE (eclipse)
* Vision Control (git)
* Documentation (doxygen)
* Continous Integration (github travis coveralls)
* Unit test framework (Goolge test)
* Code analisis (cpplint)
* Debugging (Valgrind)
* Application library (OpenCV)
* Build framework (cmake,GCC)
---
## Need To Do and Update:
* There are some issues with the gmock and probably the way I use virtual class is not correct,  the actual funcion of the virtual funtion is never been called. (17/10/2017)
* Can't let Travis pass the build, since it can't find the OpenCV config file
