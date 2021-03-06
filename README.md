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

The Graham Scan Algorithm follows these steps:
- Finds the lowest point (Y-axis) and the left-most point (X-axis)
- Sort the points by polar angle in a counterclockwise order
- Check for collinear points (The distance = 0) 
- Determine if three points make a left or right turn 
- Create two vectors type - Push points to hull vector that are convexed points 
- Push points to disregardSet vector that are concaved points 
- Store points into a CSV file

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

# Instructions to produce a convex hull
Download this repository and navigate to the `Source Code` folder of this repository.

We utilized the benefits of a `Makefile` to run and compile our programs more efficiently than typing them in individually.
To use this you can type the following commands into the terminal:

 1. `make`
 2. `./output`
  
this compiles every `.cpp` file we used. Next comes the user input. At this step, the program will now ask you to input the number of pairs
and a seed to produce a randomized set of pairs. If you chose to use your own data, make sure the `.csv` file contains two columns, one with x coordinate values and the other column with y coordinate values. The last input is to enter a `1` if you'd like to create a convex hull using the Graham Scan algorithm,
or a `2` if you'd like to do it using the quickhull algorithm.

After the input is entered and the file runs, it outputs either `grahamPairs.csv` or `quickhullPairs.csv` depending on which alogrithm you chose. These `.csv` contain the set of points in a way that can be interpreted by the visualization program.

To run this python program, you will need to have matplotlib installed. You should use the latest release of python. If you do not have matplotlib installed on your machine, you can find instructions [here](https://matplotlib.org/3.3.3/users/installing.html/ "Title"). If it is installed, enter `python3 visualization.py` and it will ask for the location of the `.csv` file to which you enter either `grahamPairs.csv` or `quickhullPairs.csv`, again, depending on what algorithm you chose before.
