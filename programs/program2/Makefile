program2: program2.o funcs.o
	gcc program2.o funcs.o -o program2  

program2.o: program2.c funcs.o
	gcc -c program2.c -Wall

funcs.o: funcs.c funcs.h
	gcc -c funcs.c -Wall
