all: Pilha.o item.o balanceada.o main.o
	gcc *.o -o bb -std=c99 -Wall

Pilha.o:
	gcc -c Pilha.c

circulo.o:
	gcc -c circulo.c

balanceada.o:
	gcc -c balanceada.c

item.o:
	gcc -c item.c

main.o:
	gcc -c main.c

run:
	./bb

zip:
	zip zip makefile *.c *.h

clean:
	rm *.o *.zip bb 

