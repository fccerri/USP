objetos = Loja.java Produto.java CD.java DVD.java Livro.java

all:
	javac Main.java $(objetos)

run:
	java Main

zip:
	zip loja_zip makefile Main.java $(objetos)

clean:
	rm *.class *.zip