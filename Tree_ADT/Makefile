all: tree
	

tree: tree.o 
	gcc -o tree tree.o 

tree.o: tree.c tree_types.h tree_API.h
	gcc -c tree.c 
