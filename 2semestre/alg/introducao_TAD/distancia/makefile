all: ponto.o circulo.o main.o
	gcc ponto.o circulo.o main.o -o dist -std=c99 -Wall -lm

circulo.o:
	gcc -c circulo.c 

ponto.o:
	gcc -c ponto.c 

main.o:
	gcc -c main.c 

run:
	./dist

zip:
	zip zip_dist makefile *.h *.c

clean:
	rm *.o *.zip dist

