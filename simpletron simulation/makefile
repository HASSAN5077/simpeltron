

simple.exe: simple.o libmystaticlib.a
	gcc -o simple.exe simple.o -L. -lmystaticlib

simple.o: simple.c simple.h
	gcc -c simple.c

util.o: util.c
	gcc -c util.c


libmystaticlib.a: util.o
	ar cr libmystaticlib.a util.o

clean:
	rm *.o libmystaticlib.a test