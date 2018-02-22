
stack: stack.o API.o
	gcc -o a.out stack.o API.o && ./a.out

stack.o: stack.c API.h types.h
	gcc -c stack.c

API.o: API.c API.h types.h
	gcc -c API.c

clean:
	rm *.o

