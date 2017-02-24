all: pthread

pthread: hw2.o
	gcc -o pthread hw2.o -pthread

hw2.o:hw2.c
	gcc -c hw2.c 


dep:
	gcc -M *.c > .depend


clean:
	rm -f *.o pthread .depend
