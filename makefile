all: matrix.c gen.c main.c
	cc -c matrix.c
	cc -c gen.c
	cc -c main.c
	cc *.o -o gra

matrix.o: matrix.c matrix.h
gen.o: gen.c gen.h
main.o: main.c

test: all
	./gra 8
