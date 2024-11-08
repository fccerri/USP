all: item.o main.o ab.o
	gcc *.o -o EstrBin -Wall -std=c99 -Wextra

item.o: item.c
	gcc -c item.c 

main.o: main.c
	gcc -c main.c

ab.o: ab.c
	gcc -c ab.c
run:
	./EstrBin

clean: 
	rm *.o *.zip EstrBin

zip:
	zip EstrBin makefile *.c *.h
