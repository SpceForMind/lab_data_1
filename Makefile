all: menu
	
menu: menu.o index_first_negative.o index_last_negative.o multi_between_negative.o multi_before_and_after_negative.o
	gcc -o menu menu.o index_first_negative.o index_last_negative.o multi_between_negative.o multi_before_and_after_negative.o

menu.o: menu.c function.h
	gcc -c menu.c

index_first_negative.o: index_first_negative.c
	gcc -c index_first_negative.c

index_last_negative.o: index_last_negative.c
	gcc -c index_last_negative.c

multi_between_negative.o: multi_between_negative.c 
	gcc -c multi_between_negative.c

multi_before_and_after_negative.o: multi_before_and_after_negative.c 
	gcc -c multi_before_and_after_negative.c


