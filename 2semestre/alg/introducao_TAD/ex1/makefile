all: ponto.o circulo.o main.o
	gcc ponto.o circulo.o main.o -o mm -std=c99 -Wall

ponto.o:
	gcc -c ponto.c

circulo.o:
	gcc -c circulo.c

main.o:
	gcc -c main.c

run:
	./mm

zip:
	zip zip makefile *.c *.h

clean:
	rm *.o *.zip mm 

