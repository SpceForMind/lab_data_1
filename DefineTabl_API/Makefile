all: list

list: defn_tabl.o
	gcc -o defn_tabl.o

defn_tabl.o: defn_tabl.c types.h list_API.h
	gcc -c defn_tabl.c
