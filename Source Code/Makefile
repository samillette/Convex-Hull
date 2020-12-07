output: main.o quickHull.o randompairs.o point.o line.o convexFileHandling.o
	g++ main.o quickHull.o randompairs.o point.o line.o convexFileHandling.o -o output

main.o: main.cpp
	g++ -c main.cpp

quickHull.o: quickHull.cpp
	g++ -c quickHull.cpp

randompairs.o: randompairs.cpp
	g++ -c randompairs.cpp

point.o: point.cpp
	g++ -c point.cpp

line.o: line.cpp
	g++ -c line.cpp

convexFileHandling.o: convexFileHandling.cpp
	g++ -c convexFileHandling.cpp

clean:
	rm *.o output