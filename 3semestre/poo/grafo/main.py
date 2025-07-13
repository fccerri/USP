from Grafo import Grafo

line = []
lines = []
count = 0
vizinhos = {} 
Cidades = Grafo()
nomeCidade = []

while True:
    try:
        line = input()
        count += 1
        lines.append(line)
    except EOFError:
        break

for i in range(count):

    if lines[i][0] == '\t': #cidade é destino
        vizinho = lines[i].strip().split() 
        vizinhos[vizinho[0]] = int(vizinho[1])
    else: 
        if vizinhos != {}:
            Cidades.adicionaCidade(nomeCidade, vizinhos)
        vizinhos = {}       
    
    if lines[i][0] != '\t': #cidade origem
        nomeCidade = lines[i].strip()

if nomeCidade is not None: #add a ultima cidade
    Cidades.adicionaCidade(nomeCidade, vizinhos)
    

tam = Cidades.tamanho
for i in range(tam):
    for j in range(tam):
        if i == j: 
            continue

        distancia, caminho = Cidades.djikstra(Cidades.nomes[i], Cidades.nomes[j])

        print(Cidades.nomes[i] + " para " + Cidades.nomes[j])
        print("\tDistancia: " + format(distancia) + ",0")
        print("\tCaminho: ", end="")
        for cidade in caminho:
            print(" --> " + cidade, end="")
            
        print()

    print("---------------------------------------------")

    
            
