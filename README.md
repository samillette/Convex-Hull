# CSC 212 Convex Hull Final Project

This project is the compilation of all things related to my group's work on our final project for our CSC 212 class. The class focused on data structures and abstrations.

# Convex-Hull
In order to better understand our project itself, its important to understand the mathematical concept behind our project, the **Convex Hull**.

Convex Hulls have many real life applications:
  - Collision avoidance
      - In video games
      - roomba/robotics
  - Tracking Disease Epidemic
  - Nuclear/Chemical Leak Evacuation
  - Basketball



# Graham Scan
Our task was to code the [Graham Scan Algorithm](https://en.wikipedia.org/w/index.php?title=Graham_scan&oldid=981736794) and create a visualization of the processed data.

<p align="center"><img width=20% src="https://github.com/samillette/Convex-Hull/blob/main/Presentation%20Materials/GrahamScanDemo.gif"></p>
<p align="center">The Graham Scan Algorithm</p>

# Quickhull
We chose to go a step further and do an additional algorithm for comparison with the Graham Scan Algorithm. The additional algorithm implemented was the [Quickhull Algorithm](https://en.wikipedia.org/w/index.php?title=Quickhull&oldid=986184164).

<p align="center"><img width=20% src="https://github.com/samillette/Convex-Hull/blob/main/Presentation%20Materials/Animation_depicting_the_quickhull_algorithm.gif"></p>
<p align="center">The Quickhull Algorithm</p>

The quickhull algorithm follows these steps:
- Find the leftmost and rightmost coordinates on the plain
- Define a line between these two points and partition the remaining points into two subsets of those above the line and those below the line
- For each subset, determine the point furthest from the line which the subset 'belongs' to
- Generate a tringle from this point and the base line. Points within that triangle **cannot** be part of the convex hull, discard
- Recursively repeat the two previous steps with the subsets determined by the new outside lines of the triangle. Continue on until no points remain in every subset, at this point recursion ends and the convex hull is found

# About this code
This project's algorithms are written in c++ 2011, and the visualization tool is written in python 3.

