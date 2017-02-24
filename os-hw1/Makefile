all: my_shell

my_shell: b023040020.o
	gcc -o my_shell b023040020.o

b023040020.o:b023040020.c
	gcc -c b023040020.c


dep:
	gcc -M *.c > .depend


clean:
	rm -f *.o my_shell .depend
