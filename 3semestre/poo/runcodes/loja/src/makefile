objetos = Loja.java Produto.java CD.java DVD.java

all:
	javac Main.java $(objetos)

run:
	java Main

zip:
	zip loja_zip Makefile Main.java $(objetos)

clean:
	rm *.class *.zip