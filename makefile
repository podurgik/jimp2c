all: matrix.c gen.c png.c lodepng.c main.c
	cc -c matrix.c
	cc -c gen.c
	cc -c png.c
	cc -c lodepng.c
	cc -c main.c
	cc *.o -o gra

matrix.o: matrix.c matrix.h
gen.o: gen.c gen.h
png.o: png.c png.h
lodepng.o: lodepng.c lodepng.h
main.o: main.c

test: all
	./gra 9

clean:
	rm *.o
	rm *.png
