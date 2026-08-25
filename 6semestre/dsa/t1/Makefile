CC = gcc
CFLAGS = -Wall -Wextra -lm

.PHONY: all main tests check clean

# Compila o programa principal
all: main

main: main.c
	$(CC) -o main main.c $(CFLAGS)

# Gera os 10 casos de teste (entradas/ e saidas/) executando o script python
tests: main
	python3 gen_tests.py

# Executa main com cada entrada e compara com a saída esperada
check: tests
	@passed=0; failed=0; total=0; \
	for entrada in entradas/*.in; do \
		num=$$(basename $$entrada .in); \
		saida_esperada="saidas/$$num.out"; \
		saida_obtida=$$(./main < $$entrada); \
		saida_esperada_conteudo=$$(cat $$saida_esperada); \
		total=$$((total + 1)); \
		if [ "$$saida_obtida" = "$$saida_esperada_conteudo" ]; then \
			printf "[PASS] Caso $$num\n"; \
			passed=$$((passed + 1)); \
		else \
			printf "[FAIL] Caso $$num\n"; \
			printf "  Esperado: %s\n" "$$saida_esperada_conteudo"; \
			printf "  Obtido:   %s\n" "$$saida_obtida"; \
			failed=$$((failed + 1)); \
		fi; \
	done; \
	echo ""; \
	echo "Resultado: $$passed/$$total passaram, $$failed falharam"

# Limpa arquivos gerados
clean:
	rm -f main
	rm -rf entradas/ saidas/
