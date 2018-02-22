
count_key_words: count_key_words.o API.o
	gcc -o a.out count_key_words.o API.o && ./a.out <test_count_key_words

count_key_words.o: count_key_words.c types.h constant.h API.h
	gcc -c count_key_words.c

API.o: API.c types.h constant.h API.h
	gcc -c API.c 

clean:
	rm *.o count_key_words.o API.o a.out

