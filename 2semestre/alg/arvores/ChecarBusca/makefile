all: item.o main.o ab.o
	gcc *.o -o checaBusca -Wall -std=c99 -Wextra

item.o: item.c
	gcc -c item.c 

main.o: main.c
	gcc -c main.c

ab.o: ab.c
	gcc -c ab.c
run:
	./checaBusca

clean: 
	rm *.o *.zip checaBusca

zip:
	zip checBsc makefile *.c *.h
