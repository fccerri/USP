all: item.o rpn.o Pilha.o
	gcc *.o -o rpn -std=c99 -Wall

item.o:
	gcc -c item.c 

rpn.o:
	gcc -c rpn.c 

Pilha.o:
	gcc -c Pilha.c 

run: 
	./rpn

clean: 
	rm *.o rpn *.zip

zip:
	zip rpn rpn.c
