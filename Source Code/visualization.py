import csv
import sys
from os import path

import matplotlib.pyplot as plt

"""

This file creates a visualization of the convex hull

"""

def get_file_path():
    filepath = input("Enter the path of the csv file you wish to visualize or 'quit' to quit program: ")
    fileexists = path.exists(filepath)

    if filepath == "quit":
        sys.exit("User quit program")

    while not fileexists:
        filepath = input("File path does not exist \n Enter a valid filepath or 'quit' to quit program: ")
        fileexists = path.exists(filepath)

        if filepath == "quit":
            sys.exit("User quit program")

    return filepath

def main():

    """
    
    Here we are just getting the file path which we want to parse
    Because user input is not always the best, and to keep thing relatively user friendly, we included some
    checks here.
    
    """

    filepath = get_file_path()

    vertexlist = ([], [])
    edgelist = []

    with open(filepath) as csvfile:
        readcsv = csv.reader(csvfile, delimiter = ",")

        for row in readcsv:

            # If third item points to nothing, add coordinates to the vertex cloud list
            if row[2] == "-1":
                x = int(row[0])
                y = int(row[1])

                vertexlist[0].append(x)
                vertexlist[1].append(y)

            # If the third element does point to something useful, add the two coordinate pairs to a list of edges
            else:
                x1 = int(row[0])
                y1 = int(row[1])
                x2 = int(row[2])
                y2 = int(row[3])

                edge = [(x1, y1), (x2, y2)]
                edgelist.append(edge)

    plt.suptitle("Convex Hull")
    plt.plot(vertexlist[0], vertexlist[1], "ro")
    for edge in edgelist:
        plt.plot((edge[0][0], edge[1][0]), (edge[0][1], edge[1][1]), color="b")
    plt.show()


if __name__ == "__main__":
    main()