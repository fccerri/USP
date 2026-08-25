#!/usr/bin/env python3
import os
import random
import subprocess

def gerar_vetor_ordenado(n):
    vetor = []
    atual = random.randint(1, 5)
    for _ in range(n):
        vetor.append(atual)
        atual += random.randint(1, 5)
    return vetor

def escrever_cabecalho(f, vetor, n):
    f.write(f"{n}\n")
    f.write(" ".join(map(str, vetor)) + "\n")

def escrever_comandos_completos(f, vetor, n):
    existente_inicio = vetor[0]
    existente_meio = vetor[n // 2]
    existente_fim = vetor[-1]
    inexistente = vetor[-1] + 100

    # Cmd 1: Inversão
    f.write("1\n")

    # Cmd 2, 3, 4: Buscas
    for cmd in [2, 3, 4]:
        for val in [existente_inicio, existente_meio, existente_fim, inexistente]:
            f.write(f"{cmd}\n{val}\n")

    # Cmd 5: Encerrar
    f.write("5\n")

def gerar_saida(nome_entrada, nome_saida):
    with open(nome_entrada, 'r') as fin, open(nome_saida, 'w') as fout:
        subprocess.run(['./main'], stdin=fin, stdout=fout, check=True)

def main():
    os.makedirs('entradas', exist_ok=True)
    os.makedirs('saidas', exist_ok=True)
    
    # Caso 01 - Inversão
    n = 10
    vetor = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    with open("entradas/01.in", "w") as f:
        escrever_cabecalho(f, vetor, n)
        f.write("1\n5\n")
    gerar_saida("entradas/01.in", "saidas/01.out")
    print(f"[OK] Caso 01  (N = {n:2d})       ->  Inversão")
    
    # Caso 02 - Busca Sequencial
    n = 15
    vetor = [2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35, 38, 41, 44]
    with open("entradas/02.in", "w") as f:
        escrever_cabecalho(f, vetor, n)
        for val in [17, 2, 44, 99]:
            f.write(f"2\n{val}\n")
        f.write("5\n")
    gerar_saida("entradas/02.in", "saidas/02.out")
    print(f"[OK] Caso 02  (N = {n:2d})       ->  Busca Sequencial")
    
    # Caso 03 - Busca Binária Iterativa
    n = 12
    vetor = [3, 7, 12, 18, 25, 33, 42, 52, 63, 75, 88, 100]
    with open("entradas/03.in", "w") as f:
        escrever_cabecalho(f, vetor, n)
        for val in [42, 3, 100, 50]:
            f.write(f"3\n{val}\n")
        f.write("5\n")
    gerar_saida("entradas/03.in", "saidas/03.out")
    print(f"[OK] Caso 03  (N = {n:2d})       ->  Busca Binária Iterativa")
    
    # Caso 04 - Busca Binária Recursiva
    n = 8
    vetor = [10, 20, 30, 40, 50, 60, 70, 80]
    with open("entradas/04.in", "w") as f:
        escrever_cabecalho(f, vetor, n)
        for val in [30, 10, 80, 55]:
            f.write(f"4\n{val}\n")
        f.write("5\n")
    gerar_saida("entradas/04.in", "saidas/04.out")
    print(f"[OK] Caso 04  (N = {n:2d})       ->  Busca Binária Recursiva")
    
    # Caso 05 - Menu completo com vetor pequeno
    n = 7
    vetor = [5, 12, 18, 25, 33, 47, 60]
    with open("entradas/05.in", "w") as f:
        escrever_cabecalho(f, vetor, n)
        f.write("1\n2\n25\n2\n99\n3\n5\n3\n40\n4\n60\n4\n1\n5\n")
    gerar_saida("entradas/05.in", "saidas/05.out")
    print(f"[OK] Caso 05  (N = {n:2d})       ->  Menu completo (pequeno)")
    
    # Casos 06-10 - Tamanhos grandes PDF (caso 10 com 750.000 como requisitado)
    tamanhos = [1000, 50000, 100000, 500000, 750000]
    for i, size in enumerate(tamanhos):
        idx = i + 6
        vetor = gerar_vetor_ordenado(size)
        in_file = f"entradas/{idx:02d}.in"
        out_file = f"saidas/{idx:02d}.out"
        with open(in_file, "w") as f:
            escrever_cabecalho(f, vetor, size)
            escrever_comandos_completos(f, vetor, size)
        gerar_saida(in_file, out_file)
        print(f"[OK] Caso {idx:02d}  (N = {size:7d})  ->  Menu completo")

if __name__ == "__main__":
    main()
