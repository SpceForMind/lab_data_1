
points: encapsulation.o points.o
	gcc -o a.out encapsulation.o points.o

encapsulation.o: encapsulation.c point_2d.h point_3d.h
	gcc -c -fms-extensions encapsulation.c

points.o: points.c point_2d.h point_3d.h
	gcc -c -fms-extensions points.c

clean:
	rm -rf *.o
