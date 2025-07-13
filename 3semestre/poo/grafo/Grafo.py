import heapq
INF = 999999

class Grafo:
    def __init__(self):
        self.tamanho = 0
        self.grafo = {}
        self.nomes = []

    def adicionaCidade(self, cidade, vizinhos):
        self.grafo[cidade] = vizinhos
        self.nomes.append(cidade)
        self.tamanho += 1

    def djikstra(self, inicio, fim):
        q = []
        distancia = {}
        processado = {}
        anterior = {} # guarda o no anterior no caminho

        distancia[inicio] = 0
        heapq.heappush(q, (0, inicio))

        while q:
            dist_a, a = heapq.heappop(q)

            if a in processado and processado[a]:
                continue
            processado[a] = True

            for b, w in self.grafo.get(a, {}).items():  # (vizinho, peso)

                if b not in distancia: #inicializa distancia se nao exsitir
                    distancia[b] = INF

                if distancia[a] + w < distancia[b]:
                    distancia[b] = distancia[a] + w
                    anterior[b] = a 
                    heapq.heappush(q, (distancia[b], b))


        # Reconstroi o caminho
        caminho = []
        atual = fim
        while atual != inicio:
            caminho.append(atual)
            atual = anterior[atual]

        caminho.reverse()

        return distancia[fim], caminho




        

