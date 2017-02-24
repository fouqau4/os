all: pthread

pthread: hw3.o
	g++ -o pthread hw3.o -pthread

hw2.o:hw3.cpp
	g++ -c hw3.cpp 


dep:
	g++ -M *.cpp > .depend


clean:
	rm -f *.o pthread .depend
