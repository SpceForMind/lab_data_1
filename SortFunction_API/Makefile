all: sort

sort: turn_sort.o
	gcc -o a.out turn_sort.o

turn_sort.o: turn_sort.c sort.h
	gcc -c turn_sort.c
