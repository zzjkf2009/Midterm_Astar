# Acme-Robotics-Project
[![Build Status](https://travis-ci.org/zzjkf2009/Midterm Astar.svg?branch=master)](https://travis-ci.org/zzjkf2009/Midterm_Astar)

[![Coverage Status](https://coveralls.io/repos/github/zzjkf2009/Midterm Astar/badge.svg?branch=master)](https://coveralls.io/github/zzjkf2009/Midterm_Astar?branch=master)


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
### Defect log
See at: https://docs.google.com/spreadsheets/d/16HbVWjZSSKYlnzeiJM4OVrNRNsU8g1owlBgeu1AP18A/edit#gid=0 (Public)
---
## Prerequisites


---
## Installing

---
## Build

Run as fellow:
```
* mkdir build
* cd build
* cmake ..
* make
```
---
## Running and tests


---
## Test
After the build process, run the demo Test program
run:
```


./build/test/cpp-test
```

---
## Installation
- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/zzjkf2009/Astar.git
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
 * David Pietrocola -Initial Framework- see at: git clone --recursive https://github.com/dpiet/cpp-boilerplate.git 
 * Zejiang Zeng -Contributor- 
---
## LICENSE
### See at

https://github.com/zzjkf2009/Astar/master/LICENSE
