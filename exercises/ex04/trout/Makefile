trout.o: trout.c trout.h
	gcc -c trout.c

util.o: util.c util.h
	gcc -c util.c 

trout: main.c trout.c util.c
	gcc -Wall -g -o trout main.c trout.o util.o
