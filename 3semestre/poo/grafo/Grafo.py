import heapq
INF = 99999

class Grafo:
    def __init__(self):
        self.tamanho = 0
        self.grafo = {}

    def adicionaCidade(self, cidade, **kwargs):
        self.grafo[cidade] = kwargs

    def djikstra(self, inicio, fim) :
        q = []
        distancia = [INF]*self.tamanho

        for i in range(self.tamanho):
            distancia[i] = INF
            distancia[inicio] = 0
            heapq.heappush(q, (0, inicio))

            



        

