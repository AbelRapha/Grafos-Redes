grafo = []

n_vertice = 5

def novoGrafo(n_vertice):
    N = n_vertice
    for i in range(0, N):
        linha = list()
        for j in range(0, N):
            linha.append(0)
        grafo.append(linha)    

def mostraGrafo(grafo):
    for linha in grafo:
        print(linha)

def addAresta(grafo,i,j):
    A = grafo
    A[i][j] = 1
    A[j][i] = 1

def grau(grafo,v):
    soma = 0
    A = grafo
    for i in range(0,n_vertice):
        soma+= A[v][i] 
    return soma  

novoGrafo(5)   
addAresta(grafo,0,1)
addAresta(grafo,1,2)
addAresta(grafo,2,3)
addAresta(grafo,3,4)
mostraGrafo(grafo)
vertice = 4
print('grau({})={}'.format(vertice,grau(grafo,vertice)))